# I C U, You C Me

## Due Date: Tues., Sept. 17, 11:59:59 PM; Late turn-in deadline (10% off): Thurs., Sept. 19, 11:59:59pm


## Description
The following problems will give you practice writing basic programs in C, as well as reviewing some fundamental programming concepts like loops and recursion.

This assignment is not supposed to be difficult--it's mainly intended to be practice for using the terminal environment, the compiler, and Mimir. See me quickly if you find yourself struggling with any of these problems.

## Getting Started

Find the Project1 assignment in Mimir.  

You'll follow the same basic procedure you used in our Lab1 exercise:

\begin{itemize}
\item Read the specifications below and begin developing your solutions in Mimir.  Compile, run, debug as necessary.  
\item Submit your work to Mimir to run against a set of testcases.  
\item You may submit as many times as you wish; I grade the last submission before the deadline.
\item When it's time to grade the projects, I'll look over your code and the testcase results, comment on your work, and return it to you.
\end{itemize}

## Files and Grading
Submit one `.c` source file for each problem. Your files must be named `problem1.c`, `problem2.c`, etc. 

Your grade will be based on the tests you pass. I will also manually examine your files to make sure they have
reasonable style and employ good problem solving strategies  (i.e. you can't just print the expected answers). I reserve the right to deduct points for poor programming style.

## The Problems

### Problem 1: OHAI DERE
Write a program that prints `Rollins College, CMS230, Fall 2019`.

### Problem 2: Broken Arrow
```
    **
   ****
  ******
 ********
**********
    **
    **
    **
    **
```
Write a C program that can produce such an arrow, with the height of the arrow head and the height of the shaft controled by variables.  Print an arrow with an arrowhead height of 5 and a shaft of 4 (as in the above picture).  \\ 

You must use loops to print the correct arrow for any positive value of the height variable---don't just manually print the answer for 5 and 4!

*Hint:* if the height of the arrowhead is *h*, the top level has *h-1* spaces followed by two `*` characters.  The next row has *h-2* spaces followed by four `*` characters, and so forth.  The width of the shaft should always be 2. 

### Problem 3: FizzBuzz
A famous programming interview question described by Imran Gohry. Write a program that loops through the numbers from 1 to 30. Print each number, except

* For numbers divisible by 3 print `Fizz`
* For numbers divisible by 5 print `Buzz`
* For numbers divisible by 3 and 5 print `FizzBuzz`

The output for the the first six numbers will look like this:
```
1
2
Fizz
4
Buzz
Fizz
```

### Problem 4: Everyone Needs a Hobby
I'm building a wall around my house.  But I'm not very good at it.
First I place a row of *N* blocks on the ground.
Then I place *N -1* blocks on top of those, then *N-2* blocks for my 3rd row and so forth, until I finally place a single stone on the top level. A (poorly spaced) example:

```
  #
  ##
 ###
 ####
#####
```

Write a **recursive** C program that calculates the number of blocks in a ten-level wall. Your program **must use a recursive function** called `blocks` to perform the calculation. 

*Hint:* The number of blocks in a ten-level wall is the number in a nine-level wall plus 1.  In general,
\[
blocks(N) = blocks(N-1) + 1
\]

### Problem 5: Binet's Formula and Linking with Libraries
Recall the famous Fibonacci sequence, where each term is the sum of the two previous terms:
\[
1, 1, 2, 3, 5, 8, 13, 21, 34, \ldots
\]

Binet's Formula (named after the mathematician Jacques Philippe Marie Binet) is an explicit formula for finding terms in the Fibonacci sequence.  The *n*th Fibonacci number, *F_n*, is given by
\[
F_n = \frac{1}{\sqrt{5}} \left( \left( \frac{1 + \sqrt{5}}{2} \right)^n - \left( \frac{1 - \sqrt{5}}{2} \right)^n \right)
\]
The special number
\[
\phi = \frac{1 + \sqrt{5}}{2} \approx 1.618033\ldots
\]
is the famous *golden ratio*, the most aesthetically pleasing of all proportions.

The formula can be derived using **generating functions**, which are awesome but not part of this course.

Write a C program that uses Binet's Formula to calculate and print the first 10 Fibonacci numbers.  Use `sqrt` and `pow` to perform the calculations; both functions are defined in `math.h`. Look up both commands to see how they're used. 

To use the `pow` function, you'll need to `link` your code with the math library.  **Libraries** are pre-compiled collections of useful routines.  The linking process merges this pre-compiled code into your executable.

Use the `-l` flag to link a library.  The appropriate command is
```
gcc -Wall -Werror -o problem5 problem5.c -lm
```

`gcc` processes the `-l` flag by interpreting the rest of the flag, the letter `m`, as the name of a library. It uses that name to generate a library name in the standard form (`libm.a`), then looks up the library and adds it to your program.

## Submission

Don't forget to complete the README.md file in your repo.  Make sure your code is clean and commented.  Then do a final push to GitHub.  Remember that you can log on to the GitHub website and verify your submission. 
