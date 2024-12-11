#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> bitStuffing(const vector<int>& data) {
    vector<int> stuffedData;
    int oneCount = 0;

    for (int bit : data) {
        stuffedData.push_back(bit);
        if (bit == 1) {
            oneCount++;
            if (oneCount == 5) {
                stuffedData.push_back(0);
                oneCount = 0;
            }
        } else {
            oneCount = 0;
        }
    }

    return stuffedData;
}

vector<int> bitDestuffing(const vector<int>& stuffedData) {
    vector<int> destuffedData;
    int oneCount = 0;

    for (int i = 0; i < stuffedData.size(); ++i) {
        int bit = stuffedData[i];

        if (bit == 1) {
            destuffedData.push_back(bit);
            oneCount++;
            if (oneCount == 5) {
                // Skip the next 0 after 5 consecutive 1's
                if (i + 1 < stuffedData.size() && stuffedData[i + 1] == 0) {
                    i++; // Skip the stuffed 0
                }
                oneCount = 0; // Reset the one count
            }
        } else {
            destuffedData.push_back(bit);
            oneCount = 0;
        }
    }

    return destuffedData;
}


vector<int> parseInputToBits(const string& input) {
    vector<int> bits;
    for (char c : input) {
        if (c == '0' || c == '1') {
            bits.push_back(c - '0');
        } else {
            cerr << "Invalid input: please use only '0' and '1'." << endl;
            exit(EXIT_FAILURE);
        }
    }
    return bits;
}

void printBits(const vector<int>& bits) {
    for (int bit : bits) {
        cout << bit;
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter the bit sequence (use '0' and '1' only): ";
    getline(cin, input);

    vector<int> data = parseInputToBits(input);
    vector<int> stuffed = bitStuffing(data);
    vector<int> destuffed = bitDestuffing(stuffed);

    cout << "Original Data: ";
    printBits(data);

    cout << "Stuffed Data:  ";
    printBits(stuffed);

    cout << "Destuffed Data: ";
    printBits(destuffed);

    return 0;
}
