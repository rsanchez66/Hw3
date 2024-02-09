#include <iostream>
#include <string>

// Convert plaintext to ciphertext using substitution cipher
std::string encrypt(const std::string& plaintext, const char cipher[]) {
    std::string ciphertext;
    for (char ch : plaintext) {
        if (std::isalpha(ch) && std::isupper(ch)) {
            int index = ch - 'A'; // Calculate the letter in the alphabet
            ciphertext += cipher[index]; // Substitute letter with corresponding cipher letter
        } else {
            ciphertext += ch; // Keep punctuation and other characters
        }
    }
    return ciphertext;
}

int main() {
    const char cipher[26] = {'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W'};

    std::string plaintext;
    std::cout << "Enter the plaintext message (uppercase letters and punctuation only): ";
    std::getline(std::cin, plaintext);

    std::string ciphertext = encrypt(plaintext, cipher);
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    return 0;
}