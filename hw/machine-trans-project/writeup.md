# A Binary Precaution Against Hex*
## Due Thursday, December 5th, 11:59:59 PM

## Description
This semester, we've learned to understand data representation at the bit level.  That is, you now know how to interpret a bit pattern if you are told those bits represent (for example), a 2's complement 32-bit integer.  You've also learned ASCII character representations and IEEE-764 Floating Point representation.  The one thing we haven't covered are instructions.  If you see a 32-bit pattern and are told it represents an ARM machine instruction, how does that work?

We know that assembly languages are designed to work with a specific chipset (family of chips).  But how?  How does the assembly language map to the bits patterns that the chip understands?  This assignment is designed to:
* help you understand the mapping between (ARM) assembly and (ARM) machine language.
* give you some experience reading and understanding instruction set architectures (ISAs) which describe the specifics of assembly instructions and their formats.
* give you some practice manipulating bit patterns in C using bitwise operators.  
* work with basic I/O in C

To understand the mapping between assembly language menonics and the binary patterns of machine language we must understand how to *decode* the binary pattern into the higher (barely) level ARM instructions.  We must also be able to *encode* the ARM instructions to the matching bit pattern.  For this assignment, you'll only be decoding from binary pattern to ARM mnemonic, but you'll also understand the reverse encoding process.

This assignment is based on the real ARM ISA.  It only covers a subset of the ISA, and it's been simplified for this course, but the instructions, bit patterns, and mappings are real and in use in the real world today.

## Getting Started
You will need a number of resources in your project to get started:

* The [documentation for the ARM ISA](./arm-isa.md)
* Readings about [bitwise operators](https://github.com/vsummet/cms230notes/blob/master/c-programming/c-chap13-bitwise.md) in C and [file I/O](https://github.com/vsummet/cms230notes/blob/master/c-programming/c-chap12-fileio.md) in C
* A sample input file: `sample-input.ml` (available on Mimir).
* Some starter code: `decode.c` (available on Mimir)

The starter code will read an input file, which is supplied on the command line:

```
  prompt$> gcc -Wall -Werror -o decode decode.c
  prompt$> ./decode sample-input.ml
```

Each line in the input file contains a 32-bit long bit pattern which, when decoded correctly, gives a valid ARM assembly instruction.  For this assignment, we'll be working with three categories of instructions.  Each category contains multiple assembly instructions:

1. Data Processing Instructions: `mov`, `add`, `sub`, and `cmp`.
2. Branching Instructions: `b`, `bne`, `beq`, `bgt`, `bge`, `blt`, `ble`, and `bl`
2. Single Data Transfer Instructions (Memory Access Instructions): `ldr` and `str`

While this is a small subset of ARM instructions, as you've seen, it allows us to write suprisingly powerful programs which cover a good portion of what you learned in your introductory Java classes.

Begin by reading the `decode.c` file.  There are comments in the file directing you.  Remember to keep your development efforts small!  Don't try to write the entire program at once!  This assignment naturally decomposes since you have three categories of instructions to deal with -> make each category its own function!

The end result of your program is that it should output the assembly language mapping for the given bit pattern.  Each machine langauge instruction in the input file should result in one line of output printed to the screen.  For example, the bit pattern `0xe0823003` translates to the assembly instruction `add r3, r2, r3`.  To understand these mappings, you'll need to read the ISA.  

## Grading and Submission
Don't forget to complete the README.md file.  Make sure your code is clean and commented and follows style conventions.  As always, I grade your last submission.

## Tips and Tricks
* I recommend you begin by working with the small sample file.  Try decoding some of these **on paper** using the ISA document as a guide.  The ISA has a lot of useful info in it.  Thinking about and working with the concepts contained in it will help you formulate a plan for your code and save you time down the road.
* Remember that bitwise operators have different precedence.  Just like the mathematical expression `(4 + 2) * 3` evaluates differently than `4 + 2 * 3`, the bitwise expressions `(4 & 15) >> 2` evaluates differently than `4 & 15 >> 2`.  Use parentheses to ensure you get the evaluation order you intend.
* Remember you can express integers in hex or binary format:
``` 
    int x = 0b000111   // same as int x = 7;
    int y = 0x0F       // same as int y = 15;
```
This fact is very useful when you're trying to extract specific bits.
  
<hr>

* footnote: title from Neil Gaiman, Smoke and Mirrors

