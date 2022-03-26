# Mathematics - 103cipher Project
Language: C

Cryptography is a very old science, whose goal is to secure communication, so that only its recipient could read it.
There are a lot of methods to encrypt a message, from the simplest (such as the 2,000-year-old Caesar cipher) to the most complex (such as the World War 2 Enigma code); they all need both encryption and decryption keys (sometimes identical).

In some cases (such as the Hill cipher), the key is represented by a matrix.

This is a matrix-based ciphering software, using the following process to encrypt :

  - Transcript the key into numbers using the ASCII table.
  - Convert the numbered key into a square matrix, the smallest possible size, and filling the lines first.
  - Transcript the clear message into numbers using the ASCII table.
  - Convert the numbered message into a matrix; its number of columns should fit the key matrix size, and its number of lines should be as small as possible.
  - Multiply the 2 matrices, and write the answer linearly to get the encrypted message.
 
 The decryption process logically follows from the previous encryption method, using the same key (be careful! You need to inverse the key matrix, which is not always possible).
 
 ## USAGE
 ![image](https://user-images.githubusercontent.com/91698189/160255084-79a17d27-ca15-4043-8b77-49b9caa0a721.png)

## Example
![image](https://user-images.githubusercontent.com/91698189/160255107-1b85e312-2c8d-4e4a-951e-519abd0dac77.png)
![image](https://user-images.githubusercontent.com/91698189/160255164-68c534a4-f0bb-4141-b9cf-a2b7ac23bae9.png)
![image](https://user-images.githubusercontent.com/91698189/160255193-a8097b4d-1793-4e9c-aa09-517fc07dade7.png)
