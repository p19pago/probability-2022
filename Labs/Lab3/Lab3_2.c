#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
	
	srand(60);
	int i=0, result=0;
	
	int h = 0; /* counter for Heads */
	int t = 0; /* counter for Tails */
	
	for(i=1; i<=10; i++){
		result = rand()%2;
		printf("Random integer number: %d\n", result);
		
		if (result==1){
			h++;
		} else{
			t++;
		}
	}
	
	return 0;
}
