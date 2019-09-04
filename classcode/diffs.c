/**************************************************************
File to demonstrate some crucial differences between Java and C 
***************************************************************/

#include <stdio.h>

int main(void) {

  //Difference 1: 
  //casting, promotion and demotion
  printf("Difference 1: Casting, promotion, demotion\n");
  int smaller = 24;
  double bigger = 46.8;
  
  int result_int = smaller + bigger;
  double result_double = smaller + bigger;
  
  printf("result_int: %d\n", result_int);
  printf("result_double: %f\n\n", result_double);

  printf("\nDifference 2: Booleans\n");
  //Difference 2:
  //No boolean datatype
  //boolean b = true;  //won't work.  gcc doesn't know boolean or true
  int boolean_false = 0; //use for false
  int boolean_true = 1;  //use for true
  printf("true: %i false: %i\n", boolean_true, boolean_false);
  
  //more generally, anything non-zero is true:
  int x = 2345;
  if(x) {
    printf("x is true (non-zero): %i\n\n", x);
  }

  printf("\nDifference 3: equality vs. assignment\n");
  //Difference 3: 
  //be careful!
  x = 1;
  //if(x == 1)  {  //correct! what we meant to type...
  if(x = 45) {  //easy mistake to make! will only flag at compile stage if -Wall -Werror flags are used
    printf("This will always be printed!\n");
    printf("we assign x the value of 1 in the condition of our if stmt!!");
  } else {
    
  }
  printf("x is not 1 it's %d, hahahaha!\n", x);

 
  //Difference 4: can't declare variables inside of loops
  printf("Difference 4: NO BOUNDS CHECKING!\n");
  
  int array[] = {1, 2, 3, 4, 5};
  //some compilers will make you declare the variable outside the loops
  //Mimir doesn't
  //int i;
  for(int i = 0; i < 10; i++) {
    printf("array[%d]: %d\n", i, array[i]);
  }
  
  return 0;
}