#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a =15;
    double b = 20.9;
    
    int* x = &a;
    double* y = &b;
    

    printf("sizeof(a): %ld\n", sizeof(a));
    printf("sizeof(b): %ld\n", sizeof(b));
    
    printf("sizeof(x): %ld\n", sizeof(x));
    printf("sizeof(y): %ld\n", sizeof(y));


    return EXIT_SUCCESS;
}