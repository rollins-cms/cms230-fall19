# I C U, You C Me

## Due Date: Tues., Sept. 17, 11:59:59 PM
(Late turn-in deadline (10% off): Thurs., Sept. 19, 11:59:59pm)

## Description
The following problems will give you practice writing basic programs in C, as well as reviewing some fundamental programming concepts like loops and recursion.

This assignment is not supposed to be difficult--it's mainly intended to be practice for using the terminal environment, the compiler, and Mimir. See me quickly if you find yourself struggling with any of these problems.

## Getting Started

Find the Project1 assignment in Mimir.  

You'll follow the same basic procedure you used in our Lab1 exercise:

1. Read the specifications below and begin developing your solutions in Mimir.  Compile, run, debug as necessary.  
2. Submit your work to Mimir to run against a set of testcases.  
3. You may submit as many times as you wish; I grade the last submission before the deadline.
4. When it's time to grade the projects, I'll look over your code and the testcase results, comment on your work, and return it to you.

## Files and Grading
Write 1 program named `project1.c`.  For each of the following problems, create a function named `problem1.c`, `problem2.c`, etc. which meet the specifications described below.

Your grade will be based on the tests you pass. I will also manually examine your files to make sure they have
reasonable style and employ good problem solving strategies  (i.e. you can't just print the expected answers). I reserve the right to deduct points for poor programming style (eg. mixing snake_case and camelCase, no comments, etc).

## The Problems
Remember, name your functions `problem1.c`, `problem2.c`, etc.

### Problem 1: OHAI DERE
Write a function which takes no arguments and doesn't return anything which prints `Rollins College, CMS230, Fall 2019`.

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
Write a function that can produce such an arrow, controled by 2 argument variables.  The height of the arrow head should be controlled by the first argument and the height of the shaft should be contolled by the second.  The function prints the arrow but does not return anything.  A call to `problem2(5, 4)` would produce the above arrow.  

You must use loops to print the correct arrow for any positive value of the height variables -- don't just manually print the answer for 5 and 4!

An argument with a value <= 0 is not valid, and the program should only consider valid arguments.  So, for example, the calls `problem2(0, 4)` and `problem(3, -1)` will still generate either the arrow head or shaft (depending on which argument is valid), but the call `problem2(-4,0)` would not generate any output.

*Hint:* if the height of the arrowhead is *h*, the top level has *h-1* spaces followed by two `*` characters.  The next row has *h-2* spaces followed by four `*` characters, and so forth.  The width of the shaft should always be 2. 

### Problem 3: FizzBuzz
This problem is based on a famous programming interview question described by Imran Gohry. Write a function which takes a single argument: the number of integers to print, beginning at 1. Print each number, except

* For numbers divisible by 3 print `Hey`
* For numbers divisible by 5 print `Howdy`
* For numbers divisible by 3 and 5 print `HeyHowdy`

The output for the call `problem3(6)` will look like this:
```
1
2
Hey
4
Howdy
HeyHowdy
```
If the function is called with an argument <= 0 the function should not print anything.

### Problem 4: Everyone Needs a Hobby
I am building a triangle of wooden blocks in my back yard.  First I place a row of N blocks on the ground. Then I place N-1 blocks on top of those, then N-2 blocks for my 3rd row and so forth, until I finally place a single block on the top level. A (poorly spaced) example beginning with 3 blocks:

```
    ----
    |   |
  --------
  |   |   |
-------------
|   |   |   |
-------------
```

Write a **recursive** function that calculates and returns the total number of blocks in a triangle given the number of blocks in the bottom row.  You **do not** need to print the triangle.  Just return the number of blocks.  A call to `problem4(3)` would return 6 (as seen in the diagram above).

*Hint:* The number of blocks in a ten-level wall is the number in a nine-level wall plus 10.  In general,
`
blocks(N) = blocks(N-1) + N
`

### Problem 5: Binet's Formula and Linking with Libraries
Recall the famous Fibonacci sequence, where each term is the sum of the two previous terms:
```
1, 1, 2, 3, 5, 8, 13, 21, 34, ...
```

Binet's Formula (named after the mathematician Jacques Philippe Marie Binet) is an explicit formula for finding terms in the Fibonacci sequence.  The *n*th Fibonacci number, *F<sub>n</sub>*, is given by



<!--
\[
F_n = \frac{1}{\sqrt{5}} \left( \left( \frac{1 + \sqrt{5}}{2} \right)^n - \left( \frac{1 - \sqrt{5}}{2} \right)^n \right)
\]
The special number
\[
\phi = \frac{1 + \sqrt{5}}{2} \approx 1.618033\ldots
\]
is the famous *golden ratio*, the most aesthetically pleasing of all proportions.
-->

![Eqn](http://www.sciweavers.org/tex2img.php?eq=%5C%5B%0AF_n%20%3D%20%5Cfrac%7B1%7D%7B%5Csqrt%7B5%7D%7D%20%5Cleft%28%20%5Cleft%28%20%5Cfrac%7B1%20%2B%20%5Csqrt%7B5%7D%7D%7B2%7D%20%5Cright%29%5En%20-%20%5Cleft%28%20%5Cfrac%7B1%20-%20%5Csqrt%7B5%7D%7D%7B2%7D%20%5Cright%29%5En%20%5Cright%29%0A%5C%5D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)

The special number
![Eqn2](http://www.sciweavers.org/tex2img.php?eq=%5C%5B%0A%5Cphi%20%3D%20%5Cfrac%7B1%20%2B%20%5Csqrt%7B5%7D%7D%7B2%7D%20%5Capprox%201.618033%5Cldots%0A%5C%5D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)
is the famous *golden ratio*, the most aesthetically pleasing of all proportions.

The formula can be derived using **generating functions**, which are awesome but not part of this course.

Write a function that uses Binet's Formula to calculate and print the first N Fibonacci numbers where N is an argument passed to the function.  Use `sqrt` and `pow` to perform the calculations; both functions are defined in `math.h`. Look up both commands to see how they're used. 

To use the `pow` function, you'll need to `link` your code with the math library.  **Libraries** are pre-compiled collections of useful routines.  The linking process merges this pre-compiled code into your executable.

Use the `-l` flag to link a library.  The appropriate command is
```
gcc -Wall -Werror -o problem5 problem5.c -lm
```

`gcc` processes the `-l` flag by interpreting the rest of the flag, the letter `m`, as the name of a library. It uses that name to generate a library name in the standard form (`libm.a`), then looks up the library and adds it to your program.

## Submission

Don't forget to complete the README.md file in your repo.  Make sure your code is clean and commented.  Then do a final push to GitHub.  Remember that you can log on to the GitHub website and verify your submission. 
