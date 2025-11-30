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

*/

#include <iostream>

void getInput(){

}

int main () {
    //input: plaintext
    std::string plaintext;
    std::cout << "Enter plaintext: ";
    std::cin >> plaintext;
    std::cout << plaintext;
    //input: shift
    //output: ciphertext
}
