#include <bits/stdc++.h>
using namespace std;

bool isValidDecimal(const string& ip) {
    vector<int> parts;
    stringstream ss(ip);
    string part;

    while (getline(ss, part, '.')) {
        if (part.empty() || part.size() > 3 || !all_of(part.begin(), part.end(), ::isdigit)) {
            return false;
        }
        int num = stoi(part);
        if (num < 0 || num > 255) {
            return false;
        }
        parts.push_back(num);
    }
    return parts.size() == 4;
}

bool isValidBinary(const string& ip) {
    return ip.length() == 32 && all_of(ip.begin(), ip.end(), [](char c) { return c == '0' || c == '1'; });
}

void classifyIP(const string& ip) {
    if (isValidDecimal(ip)) {
        vector<int> parts;
        stringstream ss(ip);
        string part;

        while (getline(ss, part, '.')) {
            parts.push_back(stoi(part));
        }

        int firstOctet = parts[0];
        cout << "It is a valid decimal IP address\n";
        if (firstOctet >= 0 && firstOctet <= 127) {
            cout << "Class A\n";
        } else if (firstOctet >= 128 && firstOctet <= 191) {
            cout << "Class B\n";
        } else if (firstOctet >= 192 && firstOctet <= 223) {
            cout << "Class C\n";
        } else if (firstOctet >= 224 && firstOctet <= 239) {
            cout << "Class D\n";
        } else {
            cout << "Class E\n";
        }
    } else if (isValidBinary(ip)) {
        // Check the first 4 bits to determine the class
        string firstFourBits = ip.substr(0, 4);
        int firstNibble = stoi(firstFourBits, nullptr, 2); // Convert binary string to integer

        cout << "It is a valid binary IP address\n";
        if (firstNibble >= 0 && firstNibble <= 7) {
            cout << "Class A\n"; // 0000 to 0111
        } else if (firstNibble >= 8 && firstNibble <= 11) {
            cout << "Class B\n"; // 1000 to 1011
        } else if (firstNibble >= 12 && firstNibble <= 13) {
            cout << "Class C\n"; // 1100 to 1101
        } else if (firstNibble >= 14 && firstNibble < 15) {
            cout << "Class D\n";
        } else {
            cout << "Class E\n";
        }
    } else {
        cout << "It is an Invalid IP address\n";   
    }
}

int main() {
    string ip;
    cout << "Enter an IP address (decimal or binary): ";
    cin >> ip;
    classifyIP(ip);
    return 0;
}
