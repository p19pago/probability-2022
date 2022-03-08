#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char** argv){
	
	srand(3);
	int i, x;
	
	for(i=1; i<=10; i++){
		printf("Random number value is: %d \n", rand());
	}
	
	printf("Maximum random value is: %d \n", RAND_MAX);
    return 0;
}
