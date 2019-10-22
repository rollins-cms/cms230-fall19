#include <stdio.h>
#include <stdlib.h>

typedef struct bank_account_t {
   int    transactions;
   double balance;
} bank_account;
 
void update(bank_account* x) {
    printf("\tValue of pointer/parameter: %p\n", x);
    printf("\tbeginning of update function: x->transactions = %d  x->balance = %.1f\n",
		    x->transactions, x->balance);
 
    x->transactions = 1001;    // Update struct's
    x->balance = 9999.9;       // values
 
    printf("\tend of update function: x->transactions = %d  x->balance = %.1f\n",
		    x->transactions, x->balance);
}
 
int main(int argc, char *argv[]) {
    bank_account* a = malloc(sizeof(bank_account));

    a->transactions  = 123;
    (*a).balance = 1000.0;
 
    printf("Before calling update: a->transactions = %d  a->balance = %.1f value of a = %p\n",
            a->transactions, a->balance, a);
 
	// Demonstrate that struct is
	// passed-by-value -- changes
	// made to member variables in function
	// didn't effect a!!
    update (a); 

	free(a);
	
    printf("AFTER  calling update: a->transactions = %d  a->balance = %.1f\n",
 		 a->transactions, a->balance);

 	return 0;
}