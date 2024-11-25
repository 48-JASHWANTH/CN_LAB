#include <iostream>
#include <vector>
using namespace std;
  
vector<int> mod2Division(const vector<int>& dividend, const vector<int>& divisor) {
    vector<int> remainder = dividend;

    for (int i = 0; i <= dividend.size() - divisor.size(); ++i) {
        if (remainder[i] == 1) { // Perform division only if the bit is 1
            for (int j = 0; j < divisor.size(); ++j) {
                remainder[i + j] ^= divisor[j]; // XOR operation
            }
        }
    }

    // Return the remainder part
    return vector<int>(remainder.end() - divisor.size() + 1, remainder.end());
}

// Function to encode data with CRC
vector<int> encodeCRC(const vector<int>& data, const vector<int>& generator) {
    vector<int> augmentedData = data;

    // Append zeros equal to the length of the generator - 1
    augmentedData.insert(augmentedData.end(), generator.size() - 1, 0);

    // Perform Mod-2 Division to get the remainder
    vector<int> remainder = mod2Division(augmentedData, generator);

    // Append the remainder to the original data
    vector<int> encodedData = data;
    encodedData.insert(encodedData.end(), remainder.begin(), remainder.end());
    return encodedData;
}

// Function to verify the received data
bool verifyCRC(const vector<int>& receivedData, const vector<int>& generator) {
    // Perform Mod-2 Division
    vector<int> remainder = mod2Division(receivedData, generator);

    // If remainder is all zeros, data is error-free
    for (int bit : remainder) {
        if (bit != 0) return false;
    }
    return true;
}

int main() {
    // Example data and generator
    vector<int> data = {1, 0, 1, 1}; // Data bits
    vector<int> generator = {1, 0, 1}; // Generator polynomial (e.g., x^2 + 1)

    // Encode data
    vector<int> encodedData = encodeCRC(data, generator);
    cout << "Encoded Data: ";
    for (int bit : encodedData) {
        cout << bit;
    }
    cout << endl;
    cout << "Enter received data bits (space-separated): ";
    vector<int> receivedData;
    int bit;
    while (cin >> bit) {
        receivedData.push_back(bit);
    }

    if (verifyCRC(receivedData, generator)) {
        cout << "Data is error-free!" << endl;
    } else {
        cout << "Data has errors!" << endl;
    }

    return 0;
}
