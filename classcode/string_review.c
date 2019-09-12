#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //TODO 1: initialize a string variable with the value "Rollins College"
    
    char str[] = "I love Rollins College";
    //char str[] = {'R', 'o', ..., '\0'};
    
    //TODO 2: Write a loop which counts the number of 'l's in the string

    int i = 0;
    int count_l = 0;
    while(str[i] != '\0') {
        if(str[i] == 'l' || str[i] == 'L') {
            count_l++;
        }
        i++;
    }

    //TODO 3: The code should print out the original string and how many l's it contains like:
    //  Rollins College contains 4 l's.
    
    printf("%s contains %d l's\n", str, count_l);

    return EXIT_SUCCESS;
}