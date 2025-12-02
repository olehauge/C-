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
#include <math.h>
#include <vector>

int main () {
  /*

  Decryption process: 
  1. Reconstruct matrix
  2. Determin column order
  3. Fill matrix
  4. Read rows
  */
  
  // Encryption process
  std::string plaintext;
  std::cout << "Enter plaintext: ";
  std::getline(std::cin, plaintext);
  std::string ciphertext;
  int row = 4; //key + turn into input
  int column = (plaintext.length() / row); //Scytale cipher uses the diameter (rows) as the key i.e, the rows and plaintext length determine the column number
  std::vector<std::vector<char>> matrix(row, std::vector<char>(column, ' ')); // Declare matrix initiated by ' '. 
  
  /*
  PLAINTEXT = PLAINTEXTMESSAGE
  KEY = 4 (ROWS)
    0 1 2 3
  0 P L A I   C0 = PNTS
  1 N T E X   C1 = LTMA
  2 T M E S   C2 = AEEG
  3 S A G E   C3 = IXSE
  CIPHERTEXT = PNTSLTMAAEEGIXSE (C0 + C1 + C2 + C3)
  */
  int counter = 0; 
  for (int i = 0; i < row; ++i){
    for (int j = 0; j < column; ++j){
      matrix[i][j] = plaintext[counter];
      std::cout << matrix[i][j] << " ";
      ++counter; 
    }
    std::cout << std::endl;
  }

  for (int i = 0; i < column; ++i) {
    for (int j = 0; j < row; ++j) {
      ciphertext += matrix[j][i];
    }
  }
  std::cout << std::endl << "Ciphertext: " << ciphertext << std::endl;

  // Decryption process
  std::vector<std::vector<char>> decrypt_matrix(row, std::vector<char>(column, ' ')); // Declare matrix initiated by ' '. 
  int decrypt_counter = 0;

  for (int i = 0; i < column; ++i) {
    for (int j = 0; j < row; ++j) {
      decrypt_matrix[i][j] = ciphertext[decrypt_counter]; 
      std::cout << decrypt_matrix[i][j] << " ";
      ++decrypt_counter;
    }
    std::cout << std::endl;
  }
  std::string decrypted_text;
  for (int i = 0; i < column; ++i) {
    for (int j = 0; j < row; ++j) {
      decrypted_text += decrypt_matrix[j][i];
    }
  }
  std::cout << std::endl << "Decrypted message: " << decrypted_text << std::endl;
}