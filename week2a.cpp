#include <iostream>
#include <string>

using namespace std;

// Define special characters as strings
const string FLAG = "flag";   // Frame delimiter
const string ESC = "esc";     // Escape character

string characterStuffing(const string& data) {
    string stuffedData;
    stuffedData += FLAG;  // Start frame with FLAG

    int pos = 0;
    while (pos < data.length()) {
        if (data.substr(pos, FLAG.length()) == FLAG || data.substr(pos, ESC.length()) == ESC) {
            stuffedData += ESC;  // Add escape character before special strings
        }
        stuffedData += data[pos++];
    }

    stuffedData += FLAG;  // End frame with FLAG
    return stuffedData;
}

string characterDestuffing(const string& stuffed) {
    string destuffed = "";
    size_t i = 0;

    // Ignore starting flag
    if (stuffed.substr(i, FLAG.size()) == FLAG) {
        i += FLAG.size();
    }

    while (i < stuffed.size()) {
        // If flag is found at the end, break
        if (stuffed.substr(i, FLAG.size()) == FLAG) {
            break;
        }

        // Handle escape sequence
        if (stuffed.substr(i, ESC.size()) == ESC) {
            i += ESC.size(); // Skip the escape sequence
            destuffed += stuffed[i]; // Add the escaped character
        } else {
            destuffed += stuffed[i]; // Add normal character
        }
        i++;
    }

    return destuffed;
}


int main() {
    string data;
    cout << "Enter the data to be framed (use special strings like 'flag' or 'esc'): ";
    getline(cin, data);

    string stuffed = characterStuffing(data);
    string destuffed = characterDestuffing(stuffed);

    cout << "Original Data: " << data << endl;
    cout << "Stuffed Data: " << stuffed << endl;
    cout << "Destuffed Data: " << destuffed << endl;

    return 0;
}
