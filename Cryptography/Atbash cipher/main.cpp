/*
The Atbash cipher encodes a message with the reverse of the 
alphabet. When encoded, an "A" becomes a "Z", "B" turns into "Y", 
etc. 

The Atbash cipher can be implemented as an Affine cipher by 
setting both a and b to 25 (the alphabet length minus 1).

Mathematically, it is represented as e(x) = (ax + b) mod m

Decryption is a slightly different formula d(x) = a^-1 (x - b)
*/

