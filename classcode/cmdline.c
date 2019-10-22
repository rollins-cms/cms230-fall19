#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("usage: progname arg1 arg2\n");
        exit(1);
    }
    
    printf("%s\n", argv[1]);
    
	int i;
	for(i = 1; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	return 0;
}