#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//variable declaration

//generic variables
int x;
int y;
int rw[1000][1000]={0,0};

//variables for subquery 1
int pos1; //position registered for our walker in x
int i; //counter for first loop

// variables for subquery 2
int j; //counter for second loop
int pos2; //position registered for our walker in y

int main(int argc, char** argv){
	
	srand(time(NULL));

	x = rand()%1000+1;
	printf("Random number result is (for x variable): %d\n", x);
	
	y = rand()%1000+1;
	printf("Random number result is (for y variable): %d\n", y);
	
	for(i=0; i<=1000; i++){
		for(j=0; j<1000; j++){
			
			if(x>500 && y>500){
				pos1 = x+1;
				pos2 = y;
			}
			else if(x<500 && y<500){
				pos1 = x-1;
				pos2 = y;
			}
			else if(x<500 && y>500){
				pos1 = x;
				pos2 = y+1;
			}
			else if(x>500 && y<500){
				pos1 = x;
				pos2 = y-1;
			}
		}
		
		printf("%d\n", pos1);
		printf("%d\n", pos2);
	}
	
	printf("%d\n", pos1);
	printf("%d\n", pos2);
	
	FILE *fp1;
	fp1 = fopen("walkers1_lab8.txt", "w");
	fprintf(fp1, "%d\n", pos1, pos2);
	
	return 0;
}
