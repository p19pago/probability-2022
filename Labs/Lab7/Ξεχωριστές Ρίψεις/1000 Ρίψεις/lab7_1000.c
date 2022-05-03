#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// generic variables

int x; //random variable
int rw[1000]={0}; //amount of walks

// variables for subquery 1

int pos1; //position registered for our walker
int i; //counter for first loop
int s1;

// variables for subquery 2

int j; //counter for second loop
int pos2; //position registered for our walker
int s2;

// variables for subquery 3

int h = 0; // counter for Heads
int t = 0; // counter for Tails
int r; //expected result for heads/tails experiment
int k; //counter for third loop

int pos_h; //position for Heads
int pos_t; //position for Tails

int s3;
int s4;

// variance - mean
double m; //variable for mean
double v; //variable for variance
int sum = 0;
double sqdiff = 0;

int main(int argc, char** argv){
	
	//subquery 1

	srand(time(NULL));
	for(i=0; i<=1000; i++){
		x = rand()%10+1;
		printf("Random number result is: %d\n", x);
		
		if(x>5){
			
			pos1 = 500 + 1;
			s1 = rw[pos1];
			
			printf("%d\n", s1);
			
		}
		
		if(x<5){
			
			pos1 = 500 - 1;
			s1 = rw[pos1];
			
			printf("%d\n", s1);
			
		}
		
		printf("%d\n", pos1);
		
		FILE *fp1;
		fp1 = fopen("walkers1.txt", "w");
		
		fprintf(fp1, "%d\n", pos1);
	}
	
	//subquery 2
	
	srand(time(NULL));
	for(j=0; j<=1000; j++){
		x = rand()%10+1;
		printf("Random number result is: %d\n", x);
		
		if(x>5){
			
			pos2 = 500 + 1;
			s2 = rw[pos2];
			
			printf("%d\n", s2);
			
		}
		
		if(x<5){
			
			pos2 = 500 - 1;
			s2 = rw[pos2];
			
			printf("%d\n", s2);
			
		}
		
		printf("%d\n", pos2);
		
		FILE *fp2;
		fp2 = fopen("walkers2.txt", "w");
		
		fprintf(fp2, "%d\n", pos2);
	}
	
	//subquery 3
	
	for(k=1; k<=10; k++){
		
		r = rand()%10 +1;
		printf("Random integer number: %d\n", r);
		
		if(r>5){
			
			pos_h = 500 + 1;
			s3 = rw[pos_h];
			
			printf("%d\n", s3);
			h++;
		}
		
		printf("%d\n", pos_h);
		
		if(x<5){
			
			pos_t = 500 - 1;
			s4 = rw[pos_t];
			
			printf("%d\n", s4);
			t++;
		}
		
		printf("%d\n", pos_t);
		
		// variance - mean
		
		// 1. variance
		
		// for heads
		
		sum = sum + pos_h;
		sqdiff = sqdiff + (pos_h - m) * (pos_h - m);
		
		v = sqdiff/k;
		
		printf("%f\n", v);
		
		// for tails
		
		sum = sum + pos_t;
		sqdiff = sqdiff + (pos_t - m) * (pos_t - m);
		
		v = sqdiff/k;
		
		printf("%f\n", v);
		
		// 2. mean
		
		// for heads
		
		sum = sum + pos_h;
		m = sum/k;
		printf("%f\n", m);
		
		// for tails
		sum = sum + pos_t;
		m = sum/k;
		printf("%f\n", m);
	}
	
	return 0;
}
