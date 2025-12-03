/*
A Polybius square is a 5x5 grid used for creating a simple substitution cipher where each letter
is replaced by its row and column coordinates, usually with the letters 'I' and 'J' sharing one cell. 
It was developed by the ancient Greek historian Polybius and was initially used for long-distance 
signaling with torches. 

  0 1 2  3  4
0 A B C  D  E
1 F G H I/J K
2 L M N  O  P
3 Q R S  T  U
4 V W X  Y  Z 

Encryption: Find the letter in the grid and replace it with its coordinates. 
The row number is typically written before the column number.

Decryption: Replace each pair of coordinates with the corresponding letter from the grid.

Shared square: To make a message secret, the sender and receiver must agree on a 
specific Polybius square arrangement beforehand. This ca be acheived with a key 
with the letters (without duplicates) of the key being placed at the beginning and 
the remaining letters following it in alphabetical order

  0 1  2  3 4
0 P O  R  S C 
1 H E  A  B D
2 F G I/J K L
3 M N  Q  T U
4 V W  X  Y Z

METHOD
A method involves a Bifid cipher without a key (or, in other words, with a key of plain alphabet).
The message is transformed into coordinates on the Polybius square, and the coordinates are recorded vertically.
Letter	                s	o	m	e	t	e	x	t
Horizontal coordinate	  3	4	2	5	4	5	3	4
Vertical coordinate	    4	3	3	1	4	1	5	4

Then the coordinates are read row by row: 34  25  45  34  43  31  41  54

The obtained primary ciphertext is encrypted again. It is 
written out without being split into pairs: 3425453443314154

The resulting sequence of digits is cyclically shifted to the left by 
one step (an odd number of steps [move 3 to the end]): 4254534433141543

This sequence is again divided into groups of two: 42 54 53 44 33 14 15 43
And is replaced with the final ciphertext according to the table:

Horizontal coordinate	  4	5	5	4	3	1	1	4
Vertical coordinate	    2	4	3	4	3	4	5	3
Letter	                i	u	p	t	n	q	v	o
Thus, after encryption, we get "iuptnqvo".

*/

#include <iostream>
#include <unordered_map>
#include <algorithm> 
#include <cctype>    
#include <vector>
#include <typeinfo>

std::string IsSafeInput(std::string input) {
  for (char c : input) {
    if (!std::isalpha(c)) {
      std::cout << "Plaintext cannot contain numbers.";
      break;
    } else if (!std::isupper(c)) {
      std::transform(input.begin(), input.end(), input.begin(),
      [](unsigned char c) {return std::toupper(c);});
    } else if (c == ' ') {
      input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
    }
  }
  return input;
}

int main() {
  // Key -> value instance
  std::unordered_map<char, std::string> polybus_square;
  polybus_square['A'] = "11"; polybus_square['B'] = "21"; polybus_square['C'] = "31"; polybus_square['D'] = "41"; polybus_square['E'] = "51";
  polybus_square['F'] = "12"; polybus_square['G'] = "22"; polybus_square['H'] = "32"; polybus_square['I'] = "42"; polybus_square['J'] = "42"; polybus_square['K'] = "52"; 
  polybus_square['L'] = "13"; polybus_square['M'] = "23"; polybus_square['N'] = "33"; polybus_square['O'] = "43"; polybus_square['P'] = "53";
  polybus_square['Q'] = "14"; polybus_square['R'] = "24"; polybus_square['S'] = "34"; polybus_square['T'] = "44"; polybus_square['U'] = "54";
  polybus_square['V'] = "15"; polybus_square['W'] = "25"; polybus_square['X'] = "35"; polybus_square['Y'] = "45"; polybus_square['Z'] = "55";

  // Value -> key insance
  std::unordered_map<std::string, char> polybus_square_reverse;
  for (const auto& pair : polybus_square) {        
    polybus_square_reverse[pair.second] = pair.first;
  }

  // User input
  std::string plaintext = "SOMETEXT";
  std::string primary_cipher;

  // Simple encryption version
  for (char c : plaintext) {
    primary_cipher+= polybus_square[c];
  } 

  // Advanced encryption version (step. 1)
  std::string secondary_cipher;
  std::string secondary_cipher_rigth;
  std::string secondary_cipher_left;
  for (int i = 0; i < primary_cipher.length(); ++i) {
    if (i % 2 == 0) {
      secondary_cipher_left += primary_cipher[i];
    } else if (i % 2 != 0) {
      secondary_cipher_rigth += primary_cipher[i];
    }
  }
  secondary_cipher = secondary_cipher_left + secondary_cipher_rigth;

  // Advanced encryption version (step. 2)
  //(index + 3) mod length
  std::string tertiary_cipher;
  for (int i = 0; i < secondary_cipher.length(); ++i) {
    tertiary_cipher += secondary_cipher[((i+1)%secondary_cipher.length())];
  }

  // Advanced encryption version (step. 3) 
  std::string final_ciphertext;
  for (int i = 0; i < tertiary_cipher.length(); ++i) {
    std::string value;
    if (i % 2 == 0) {
      value = tertiary_cipher[i];
      value += (tertiary_cipher[i+1]);
      final_ciphertext += polybus_square_reverse[value];
    }
  }
  std::cout << "Plaintext message: " << plaintext << std::endl;
  std::cout << "Encrypted message: " << final_ciphertext << std::endl;

  std::string decoded_message;
  for (char c : final_ciphertext) {
    decoded_message += polybus_square[c];
  }

  std::string decoded_message_step2;
  for (int i = 0; i < decoded_message.length(); ++i) {
    decoded_message_step2 += decoded_message[((i-1)%secondary_cipher.length())];
  }

  std::string decoded_message_step3;
  std::string horizontal;
  std::string vertical;
  for (int i = 0; i < (decoded_message_step2.length()/2); ++i) {
    decoded_message_step3 += decoded_message_step2[i];
    decoded_message_step3 += decoded_message_step2[i+(decoded_message_step2.length()/2)];
  }

  std::string final_decoded_message;
  for (int i = 0; i < decoded_message_step3.length(); ++i) {
    std::string value; 
    if (i % 2 == 0) {
      value = decoded_message_step3[i];
      value += decoded_message_step3[i+1];
      final_decoded_message += polybus_square_reverse[value];
    }
  }

  std::cout << "Decrypted message: " << final_decoded_message << std::endl;
}