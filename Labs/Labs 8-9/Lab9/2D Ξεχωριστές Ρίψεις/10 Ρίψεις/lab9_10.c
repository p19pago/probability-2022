#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//variable declaration

//generic variables
int x;
int y;
int rw[1000][1000]={0,0};

int s;

//variables for subquery 1
int pos1; //position registered for our walker in x
int i; //counter for first loop

// variables for subquery 2
int j; //counter for second loop
int pos2; //position registered for our walker in y

int main(int argc, char** argv){
	
	srand(time(NULL));
	
	FILE *fp;
	fp = fopen("walkers_lab9.txt", "w");
	
	//for separate positions into separate files
	//before the loop
	
	FILE *fp1;
	fp1 = fopen("walkers1_lab9.txt", "w");
	
	FILE *fp2;
	fp2 = fopen("walkers2_lab9.txt", "w");
	
	//subqueries 1 and 2, altogether
	x = rand()%10+1;
	printf("Random number result is (for x variable): %d\n", x);
	
	y = rand()%10+1;
	printf("Random number result is (for y variable): %d\n", y);
	
	for(i=0; i<=10; i++){
		for(j=0; j<10; j++){
			
			if(x>500 && y>500){
				pos1 = x+1;
				pos2 = y;
				
				s = rw[pos1][pos2];
				printf("%d\n", s);
			}
			else if(x<500 && y<500){
				pos1 = x-1;
				pos2 = y;
				
				s = rw[pos1][pos2];
				printf("%d\n", s);
			}
			else if(x<500 && y>500){
				pos1 = x;
				pos2 = y+1;
				
				s = rw[pos1][pos2];
				printf("%d\n", s);
			}
			else if(x>500 && y<500){
				pos1 = x;
				pos2 = y-1;
				
				s = rw[pos1][pos2];
				printf("%d\n", s);
			}
		}
		
		printf("%d\n", pos1);
		printf("%d\n", pos2);
	}
	
	printf("%d\n", pos1);
	printf("%d\n", pos2);
	
	//for the main file "walkers_lab9.txt" 
	//they are printed after the loop
	
	fprintf(fp, "%d\n", pos1);
	fprintf(fp, "%d\n", pos2);
	
	//for the file "walkers1_lab9.txt", addressed to position 1 separately.
	//it is printed after the loop
	
	fprintf(fp1, "%d\n", pos1);
	
	//for the file "walkers2_lab9.txt", addressed to position 2 separately.
	//it is printed after the loop
	
	fprintf(fp2, "%d\n", pos2);

	return 0;
}
