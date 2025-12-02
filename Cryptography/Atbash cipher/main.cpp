/*
The Atbash cipher encodes a message with the reverse of the 
alphabet. When encoded, an "A" becomes a "Z", "B" turns into "Y", 
etc. 

The Atbash cipher can be implemented as an Affine cipher by 
setting both a and b to 25 (the alphabet length minus 1).

C = (25 - P) mod 26
or 
C = ('a' + 'z') - x 
*/
#include <iostream>
#include <string>
#include <algorithm> // Required for std::transform
#include <cctype>    // Required for std::toupper
int main (){
    std::string plaintext = "THIS IS A test";
    std::string ciphertext; 
    // Convert the string to uppercase
    std::transform(plaintext.begin(), plaintext.end(), plaintext.begin(),
                   [](unsigned char c){ return std::toupper(c); }); 
    // Encryption
    for (char p : plaintext) {
        if (p == ' '){
            ciphertext += p;
        } else {
            ciphertext += ('A' + 'Z') - p;
        }
    }
    std::cout << ciphertext << std::endl;
    plaintext = "";

    // Decryption
    for (char c : ciphertext) {
        if (c == ' ') {
            plaintext += c;
        } else {
            plaintext += ('A' + 'Z') - c;
        }
    }
    std::cout << plaintext << std::endl;
}