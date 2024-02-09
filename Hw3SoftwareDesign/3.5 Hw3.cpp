#include <iostream>
#include <string>

using namespace std;

// Encrypt a plaintext message using substitution cipher
string encrypt(const string& plaintext, const char* cipher) {
    string ciphertext = plaintext;

    for (char& c : ciphertext) {
        // Encrypt only uppercase letters
        if (isupper(c)) {
            // Shift character by 'A' to get index (0-25)
            int index = c - 'A';
            // Substitute character with corresponding character
            c = cipher[index];
        }
    }

    return ciphertext;
}

// Decrypt a ciphertext message using substitution cipher
string decrypt(const string& ciphertext, const char* cipher) {
    string plaintext = ciphertext;

    // Iterate through each character
    for (char& c : plaintext) {
        // Decrypt only uppercase letters
        if (isupper(c)) {
            // Find the index of the character 
            int index = 0;
            while (cipher[index] != c) {
                index++;
            }
            // Shift back to get the original character
            c = 'A' + index;
        }
    }

    return plaintext;
}

int main() {
    // Define the substitution cipher
    const char cipher[26] = {'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W'};

    // Read plaintext message
    string plaintext;
    cout << "Enter plaintext message (uppercase letters only): ";
    getline(cin, plaintext);

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, cipher);

    // Output the ciphertext
    cout << "Ciphertext: " << ciphertext << endl;

    // Decrypt the ciphertext
    string decryptedText = decrypt(ciphertext, cipher);

    // Output the decrypted
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}