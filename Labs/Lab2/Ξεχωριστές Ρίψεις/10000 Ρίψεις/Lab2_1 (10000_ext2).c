#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){

	srand(time(NULL));
	int i, j;
	int A[6];

	for(i=1; i<=10000; i++){
		for (j=1; j<=6; j++){
				A[j] = rand()%6 +1;
				printf("Random integer number: %d\n", A[j]);
			}
	}
		return 0;
	}
