# The Polybius Square Cipher

## Due Thursday, September 26, 11:59 PM

### Description
You'll implement the Polybius square, a classical substitution cipher. The cipher takes a message (the "plaintext") and converts it to an encoded output (the "ciphertext").

Basic substitution ciphers like these are much too weak to be used for any real purpose nowadays, but implementing these will give you practice working with arrays, strings, and matrices in C.

### Files and Grading

Submit one `.c` source file for each problem named `encrypt.c` and `decrypt.c` respectively. Include a `Makefile` that builds your executables from source when `make` is run at the command prompt. 

Your grade will be the percentage of tests you pass. A working build (ie, compiling from your Makefile) is essential as the testcases will not run without one. I will also manually examine your files to make sure they have
reasonable style and employ good problem solving strategies  (i.e. you can't just print the expected answers). I reserve the right to deduct points for poor
programming style.

### The Polybius Square Cipher
This cipher, named after the ancient Greek scholar Polybius, uses a special 5x5 key square to substitute letters from the plaintext with numeric codes. The contents of the square are 25 letters of the alphabet arranged in some chosen permutation. For example, 
```
    0 1 2 3 4
   ----------
0 | l a b o r
1 | c d e f g
2 | h i j k m
3 | n p s t u
4 | v w x y z
```
The omitted letter may be one that is infrequently used, like `z` or `q`, or the letter `j` may be omitted and replaced by `i`anywhere it occurs in the plaintext.

In the example above, the square has been generated using the keyword `labor`.

To encipher a message, locate its entry in the matrix, then replace it with the two-digit combination formed from the row index and the column index. For example, the letter `n` would be encoded as `31` because it is in row 3 and column 1.

Here is an example:
```
a t t a c k a t d a w n
------------------------
013333011023013311014130
```
To decrypt the message, simply use each pair of consecutive digits as a row and column lookup into the square.

### Specifics

Write two programs, `encrypt.c` and `decrypt.c` that implement the cipher.

* Use the example square given above in both programs. You don't need to write code to generate other squares.
* Each program should read a string from the user using \texttt{fgets}. Remember that the last character of the input will be a newline.
* In the encryption program, you may assume the input string will be composed of lowercase letters `a-z` with no spaces or
  punctuation. The program will print the encrypted string.
* The encryption input *may* contain the letter `j`, `q`, `z` and all other letters.  Use the testcases to help you figure out what to do in these cases.
* In the decryption program, you may assume the input will consist of the digits `0-4`. The program will print the decrypted message.
* You'll be using the automatic testcases, so you don't need to print any messages prompting the user to enter a string. Just read from the terminal using `fgets`.

### Hints:

* Start small: Make `encrypt.c` and `decrypt.c` which print a single character.  Copy and modify your `Makefile` from project 1 to build the executables `encrypt` and `decrypt`.  Submit this small set of files and ensure that the testcases are running even if you are failing them because your output is incorrect. (This means that your Makefile is correct and you don't have to worry about it again for this project).
* Read the [notes on strings](https://github.com/vsummet/cms230notes/blob/master/c-programming/c-chap08-pointers_strings.md) and [multidimensional arrays](https://github.com/vsummet/cms230notes/blob/master/c-programming/c-chap05-arrays-and-strings.md) that are
  relevant to this project.  The notes on strings also include information about using `fgets` for reading a string input from a user.
* Look up the documentation for `fgets` if you need to see some more examples.
* To convert a numeric character `c` to its corresponding integer, use `int digit = c - '0';`.  We'll talk more about this nifty trick when we talk about character encoding.

### Submission:
I grade your final submission to Mimir, so make sure that submission includes your readme file, `encrypt.c`, `decrypt.c`, and your `Makefile`.  Also, make sure you code is well styled (indentation and consistent naming) and well commented.
