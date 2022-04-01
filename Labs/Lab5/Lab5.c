#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
	srand(time(NULL));
	
	//variable declaration
	
	//loop variable declaration
	int i;
	int j;
	
	//misc variable declarations
	int c;
	int s = 0;
	int a;
	
	int r;
	
	//loops
	
	//outer loop - j
	for (j=0; j<=100; j++){
		c = 0; //we set the counter to 0 as its initial value.
		//inner loop - i
		for(i=0; i<=10; i++){
			r = rand()%2;
			printf("%d\n", r);
			
			a = 0;
			
			//if-statements inside the loop [1/2]
			//outer if-statement
			if (a == 0){
				//middle if-statement
				if (i <= 3){
					//inner if-statement
					if (r == 1){
						c++;
					}
					else{
						a = 1;
					}
				}
			}
		}
		
		//if-statements inside the loop [2/2]
		if (c == 3){
			s++;
		}
		printf("\n");
	}
	
	printf("How many times was the experiment correct, within 100 random numbers? %d\n", s);
	
	return 0;
}
