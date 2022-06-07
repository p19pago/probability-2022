#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){

	int pith;
	int i=0;

	// int h, t;

	for(i=1; i<=100000; i++){
		pith = rand()%10 + 1;
		if (pith>8){
			printf ("A \n"); // h++;
		} else{
			printf("B \n"); //t++;
		}
	}

	return 0;
}
