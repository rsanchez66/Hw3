#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// To generate a random cipher array
void generate_cipher(char cipher[]) {
// Initialize the alphabet
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Random number generator
srand(time(nullptr));

// Shuffle the alphabet to generate the cipher
string shuffled_alphabet = alphabet;
for (int i = 0; i < 26; ++i) {
// Exclude the current character from the remaining group
shuffled_alphabet.erase(remove(shuffled_alphabet.begin(), shuffled_alphabet.end(), alphabet[i]), shuffled_alphabet.end());
// Randomly select a character from the remaining
cipher[i] = shuffled_alphabet[rand() % shuffled_alphabet.length()];
// Put back the excluded character
shuffled_alphabet.push_back(alphabet[i]);
}
}

int main() {
// Initialize the cipher
char cipher[26];

// Generate the cipher
generate_cipher(cipher);

// Print the cipher
cout << "Cipher Array:\n";
for (int i = 0; i < 26; ++i) {
cout << (char)('A' + i) << " -> " << cipher[i] << "\n";
}

return 0;
}