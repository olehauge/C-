// Letters in plain text are replaced by other letters or symbols
// by shifting them a fixed number of positions in the alphabet.
// ROT3 to ROT13, shift of three or 13 positions
// The basic idea is to SUBSTITUTE one letter with another. 
/* How it works:
To cipher a given text, we need an integer value, know as a shift. 
The shift indicates the number of spots each letter of the text has
been moved down. The encryption can be represented using modular
arithmetic by first transforming the letters into numbers, 
according to the scheme:
A = 0, 
B = 1, 
...
Z = 25

Plaintext: 
Shift:
Ciphertext: 

If the shift exeeds 26, you should take modulo 26 of the result
to warp around within the alphabet. 

Features: 
1. Fixed key
2. Symmetric
3. Keyspace limited to alphabet used
*/ 

/*
First solution idea:
1. Take plaintext input -> store as string
2. Take shift number input -> store as int
3. Compare char's in plaintext with the Hash Map -> return array of integers
4. Shift array int's based on the shift number
5. Turn int's into string
6. Return shifted string

Hash map with the alphabet
    Create the hash map: unordered_map<string, int> umap;
    Insert key pairs into the hash map
        umap["A"] = 1;
        umap["B"] = 2;
        ...
        umap["Z"] = 26;

Hash map lookup for each character in the plaintext: 
    umap.find(key) -> find key in hash map
    umap[key] -> return value of key
    Put value in array OR retrun the value shiftNumber from the value (?) 


Convert char to int:
    int asciiValue = char
    A would be 65 -> 65 - 64 = 1
    B would be 66 -> 2
    OR just work with the ASCII values for the cipher logic (?) 
    If so remember that CAPS and lowcase differ in values (by a lot)
    Would not need hash map? Just shift the ASCII value with the shiftNumber?
    int wrapped_value = lower + (x - lower) % (upper - lower + 1);
    - lower = A (ASCII)
    - upper = Z (ASCII)
    - x = any CAPITAL letter
    // Adding char1 and char2 results in an int
    int sum_of_chars = char1 + char2; 

Convert int to char: 
    int ascii_value = 65; // ASCII value for 'A'
    char character = static_cast<char>(ascii_value); // character will be 'A'

Clean the input: 
- Ensure only capital letters
    if (std::all_of(begin(line), end(line), std::isalpha))
    {
        std::cout << "its characters!" << std::endl;
        break;
    }
    std::cout << "Error!" << std::endl;
    
    std::toupper
    std::isupper

How was space handled? 
if space leave it. 
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string capitalizeInput(){
    //input: plaintext
    std::string plaintext;
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plaintext);
    std::transform(plaintext.begin(), plaintext.end(), plaintext.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return plaintext;
}

std::string encrypt (std::string plaintext, int shift_number, int lower, int upper){
    std::string ciphertext; 

    for (char c : plaintext) {
        if (c == ' '){
            ciphertext += ' ';
        } else {
            int shifted_ASCII = c + shift_number;
            int cipher_number = lower + (shifted_ASCII - lower) % (upper - lower + 1);    
            char cipher_char = static_cast<char>(cipher_number); 
            ciphertext += cipher_char;
        }
    }
    return ciphertext;
}

std::string decrypt (std::string ciphertext, int shift_number, int lower, int upper){
    std::string plaintext;

    for (char c : ciphertext) {
        if (c == ' ') {
            plaintext += ' ';
        } else {
            int shifted_ASCII = c - shift_number;
            int plain_number = lower + (shifted_ASCII - lower) % (upper - lower + 1);
            char plain_char = static_cast<char>(plain_number);
            plaintext += plain_char;
        }
    }
    return plaintext;
}

int main () {
    int program_mode;
    std::cout << "Caesar cipher--choose 1 for encryption or 2 for decryption: ";
    std::cin >> program_mode;
    
    if (program_mode == 1) { // encrypt
        int shift_number; 
        
    }
    else if (program_mode == 2) { // decrypt

    }
    else {
        std::cout << "Not a valid option.";
    }

    std::string plaintext = capitalizeInput();

    int shift_number;
    std::cout << "Enter shift number: ";
    std::cin >> shift_number;

    // defining alphabet range as 'A-Z' in captial letters
    int lower = 65; // ASCII: 'A'
    int upper = 90; // ASCII: 'Z'

    // encrypt the plaintext 
    std::string ciphertext = encrypt(plaintext, shift_number, lower, upper);
    std::cout << "Your ciphertext: " << ciphertext << std::endl;

    std::cout << "The decrypted message: " << decrypt(ciphertext, shift_number, lower, upper) << std::endl;



}
