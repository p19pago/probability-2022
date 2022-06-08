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

//variables for subquery 3
int h = 0; // counter for Heads
int t = 0; // counter for Tails

int res_h; //expected result for heads experiment
int res_t; //expected result for tails experiment

int pos_h; //position for Heads
int pos_t; //position for Tails

int k; //counter for third loop, outer loop
int l; //counter for fourth loop, inner loop

//same subquery. Variables for mean and variance - no heads or tails used
double var;
double mn;
double sqdiff; //squares difference in total for both positions 1 and 2
int sum;

int sum1 = 0; //sum for position 1
int sum2 = 0; //sum for position 2
double sqdf1 = 0; //squares difference variable for position 1
double sqdf2 = 0; //squares difference variable for position 2

double v1; //variance for position 1, separately.
double v2; //variance for position 1, separately.

double mn1; //mean for position 1, separately.
double mn2; //mean for position 2, separately.

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
	x = rand()%1000+1;
	printf("Random number result is (for x variable): %d\n", x);
	
	y = rand()%1000+1;
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
