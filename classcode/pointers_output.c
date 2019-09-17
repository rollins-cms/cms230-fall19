#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a =15;
    double b = 20.9;
    
    // use the reference operator to assign a variables
    // address to a pointer.
    int* x = &a;
    double* y = &b;
    

    // different datatypes have different sizes
    printf("sizeof(a): %ld\n", sizeof(a));
    printf("sizeof(b): %ld\n", sizeof(b));
    
    // size of pointers (regardless of type of pointee)
    // is always the same since an address is the same
    // is on the chip used.
    printf("sizeof(x): %ld\n", sizeof(x));
    printf("sizeof(y): %ld\n", sizeof(y));
    
    // use the %p format specifier to print a pointer
    printf("a: %d address of a: %p\n", a, x);
    
    // use the dereference operator
    // a and *x are aliases to the same memory location
    printf("*x: %d\n", *x);
    
    // Yikes!  We forgot to dereference x and assigned our 
    // *pointer* a new value of -15.
    // Obviously, -15 is not a valid address since addresses start
    // at 0.
    x = -15;

    //Yikes!  Look at the address!
    printf("a: %d address of a: %p\n", a, x);
    
    //Segfault!  We dereferenced a pointer with a bad value
    printf("*x: %d\n", *x);
    
    return EXIT_SUCCESS;
}