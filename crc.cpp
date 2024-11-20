#include <iostream>
using namespace std;

string xorfun(string encoded, string crc) {
    int crclen = crc.length();
    for (int i = 0; i <= (encoded.length() - crclen); ) {
        for (int j = 0; j < crclen; j++) {
            encoded[i + j] = encoded[i + j] == crc[j] ? '0' : '1';
        }
        for (; i < encoded.length() && encoded[i] != '1'; i++);
    }
    return encoded;
}

int main() {
    string data, crc, encoded = "";

    // Sender Side
    cout << endl << "For sender side:" << endl;
    cout << "Enter Data bits: ";
    cin >> data;
    cout << "Enter Generator: ";
    cin >> crc;

    // Append zeros to the data bits
    encoded += data;
    int datalen = data.length();
    int crclen = crc.length();
    for (int i = 1; i <= (crclen - 1); i++) {
        encoded += '0';
    }

    // Perform XOR division to calculate the checksum
    encoded = xorfun(encoded, crc);
    string checksum = encoded.substr(encoded.length() - crclen + 1);

    // Display results
    cout << "Checksum generated is: " << checksum << endl;
    cout << "Message to be transmitted over the network: " 
         << data + checksum << endl;

    // Receiver Side
    cout << endl << "For receiver side:" << endl;
    cout << "Enter the received message: ";
    cin >> encoded;

    // Perform XOR division again to validate the received message
    encoded = xorfun(encoded, crc);

    // Check for errors
    if (encoded.substr(encoded.length() - crclen + 1).find('1') != string::npos) {
        cout << "Error in communication!" << endl;
    } else {
        cout << "No Error!" << endl;
    }

    return 0;
}
