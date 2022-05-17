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

//variables for subquery 3
int h = 0; // counter for Heads
int t = 0; // counter for Tails

int res_h; //expected result for heads experiment
int res_t; //expected result for tails experiment

int pos_h; //position for Heads
int pos_t; //position for Tails

int k; //counter for third loop, outer loop
int l; //counter for fourth loop, inner loop

//same subquery. Variables for mean and variance.
double var;
double mn;

//variables for sum and squares difference. (used in variance)
int sum_h = 0; //sum for heads
int sum_t = 0; //sum for tails
double sqdiff_h = 0; //squares difference variable for heads
double sqdiff_t = 0; //squares difference variable for tails

int main(int argc, char** argv){
	
	srand(time(NULL));
	
	//subqueries 1 and 2, altogether
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
	
	FILE *fp;
	fp = fopen("walkers_lab9.txt", "w");
	fprintf(fp, "%d\n", pos1);
	fprintf(fp, "%d\n", pos2);
	
	//for separate positions into separate files
	FILE *fp1;
	fp1 = fopen("walkers1_lab9.txt", "w");
	fprintf(fp1, "%d\n", pos1);
	
	FILE *fp2;
	fp2 = fopen("walkers2_lab9.txt", "w");
	fprintf(fp2, "%d\n", pos2);
	
	//subquery 3
	
	//heads
	res_h = rand()%1000 +1;
	printf("Random integer number: %d\n", res_h);
			
	//tails
	res_t = rand()%1000 +1;
	printf("Random integer number: %d\n", res_t);
	
	for(k=0; k<=1000; k++){
		for (l=0; l<=1000; l++){
			
			if (res_h>70 && res_t<30){
				pos_h = res_h + 1;
				pos_t = res_t;
				h++;
			}
			else if(res_h<70 && res_t>30){
				pos_h = res_h;
				pos_t = res_t + 1;
				t++;
			}
		}
		
		printf("%d\n", pos_h);
		printf("%d\n", pos_t);
		
		//for heads
		sum_h = sum_h + pos_h;
		sqdiff_h = sqdiff_h + (pos_h - mn) * (pos_h - mn);
		
		//for tails
		sum_t = sum_t + pos_t;
		sqdiff_t = sqdiff_t + (pos_t - mn) * (pos_t - mn);
		
		//mean for both heads and tails.
		mn = (sum_h + sum_t)/1000;
		printf("%f\n", mn);
		
		//variance for both heads and tails.		
		var = (sqdiff_h + sqdiff_t)/1000;
		printf("%f\n", var);
		
	}
	
	return 0;
}
