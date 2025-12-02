/*
The Scytale cipher used a batton or similar circular object to wrap a paperstrip around. 
Then write the message acorss the batton turing while rotating it when one "line" is full. 
The diameter and length of the batton determines the encryption.

Programatically this can be represented as a table with rows and columns, where the columns 
represent the diameter of the batton. 

The cipher does not allow for spaces. 
The key is the column height. 
i.e., given a number 'n' the plaintext is divided into 'n' rows. 
Encryption: 
1. Letters are inserted veritcally. 
2. Then read left to right. 

PLAINTEXTMESSAGE + key 4 
  1 2 3 4 <-- message length / key 
1 P L A I
2 N T E X
3 T M E S
4 S A G E 

PLAI NTEX TMES SAGE -> modulo 4 
PNTS LTMA AEEG IXSE

Decryption: 
1. Arrange message into 4 rows vertically 
2. Then read left to right. 
*/
#include <iostream>
#include <cstring>

int main () {
    // plaintext
    // get plaintext
    int key = 4;
    std::string plaintext = "PLAINTEXTMESSAGE";
    char ciphertext[plaintext.length()];

    for (char c : plaintext) { 
        
    }
    
}