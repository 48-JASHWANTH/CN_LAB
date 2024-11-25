#include <bits/stdc++.h>
using namespace std;

// Converts an integer to its binary representation
string toBinary(int num) {
    if (num == 0) return "0";
    string binary;
    while (num > 0) {
        binary += (num % 2) ? '1' : '0';
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

// Binary addition of two binary strings with carry
string addBinary(string a, string b) {
    int carry = 0;
    string result;
    int lenA = a.size(), lenB = b.size();
    int maxLen = max(lenA, lenB);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    for (int i = 0; i < maxLen || carry; ++i) {
        int bitA = i < lenA ? (a[i] - '0') : 0;
        int bitB = i < lenB ? (b[i] - '0') : 0;
        int sum = bitA + bitB + carry;
        result += (sum % 2) ? '1' : '0';
        carry = sum / 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Wrap around binary addition to a specified width
string wrapBinary(string binary, int width = 4) {
    while (binary.size() > width) {
        string overflow = binary.substr(0, binary.size() - width);
        string remaining = binary.substr(binary.size() - width);
        binary = addBinary(remaining, overflow);
    }
    return binary;
}

// Compute the one's complement of a binary string
string onesComplement(string binary) {
    for (char& bit : binary) {
        bit = (bit == '0') ? '1' : '0';
    }
    return binary;
}

// Check if the binary string is all zeros
bool isAllZero(string binary) {
    return binary.find('1') == string::npos;
}

int main() {
    int n, sum = 0;
    cout << "Enter number of subunits: ";
    cin >> n;

    cout << "Enter subunits:" << endl;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }

    // Sender
    cout << "Sender:" << endl;
    string sumBinary = toBinary(sum);
    cout << "Sum: " << sumBinary << endl;
    
    string wrappedSum = wrapBinary(sumBinary);
    cout << "Wrapped sum: " << wrappedSum << endl;
    
    string checksum = onesComplement(wrappedSum);
    cout << "Checksum: " << checksum << endl;

    // Simulate transmission
    int transmittedSum = sum + stoi(checksum, nullptr, 2);

    // Receiver
    cout << "\nReceiver:" << endl;
    string receivedBinary = toBinary(transmittedSum);
    cout << "Sum: " << receivedBinary << endl;
    
    wrappedSum = wrapBinary(receivedBinary);
    cout << "Wrapped sum: " << wrappedSum << endl;
    
    string result = onesComplement(wrappedSum);
    cout << "Result: " << result << endl;

    if (isAllZero(result)) {
        cout << "No error detected" << endl;
    } else {
        cout << "Error detected" << endl;
    }

    return 0;
}
