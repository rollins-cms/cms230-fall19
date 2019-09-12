#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //TODO 1: Declare an array of ints with the values 15, -3, 8, 14, and 12 in it.
    int array[] = {15, -3, 8, 14, 12};
    
    //TODO 2: Write a loop which iterates through the array and counts the number of elements
    //between 10 and 20 inclusive
    int i;
    int count = 0;
    for(i=0; i < sizeof(array)/sizeof(array[0]); i++) {
        if(array[i] >= 10 && array[i] <= 20)
        count++;
    }

    //TODO 3: The code should print the count of the elements between those values.
    printf("%d\n", count);


    return EXIT_SUCCESS;
}