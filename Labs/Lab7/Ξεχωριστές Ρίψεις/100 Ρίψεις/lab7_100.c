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
	
	FILE *fp1;
	fp1 = fopen("walkers1.txt", "w");
	
	for(i=0; i<=100; i++){
		x = rand()%10+1;
		printf("Random number result is: %d\n", x);

		if(x>5){

			pos1 = x + 1;
			s1 = rw[pos1];

			printf("%d\n", s1);
			fprintf(fp1, "%d\n", pos1);

		}

		if(x<5){

			pos1 = x - 1;
			s1 = rw[pos1];

			printf("%d\n", s1);
			fprintf(fp1, "%d\n", pos1);

		}

		printf("%d\n", pos1);
	}

	//subquery 2

	srand(time(NULL));
	
	FILE *fp2;
	fp2 = fopen("walkers2.txt", "w");
	
	for(j=0; j<=1000; j++){
		x = rand()%10+1;
		printf("Random number result is: %d\n", x);

		if(x>5){

			pos2 = x + 1;
			s2 = rw[pos2];

			printf("%d\n", s2);
			fprintf(fp2, "%d\n", pos2);
		}

		if(x<5){

			pos2 = x - 1;
			s2 = rw[pos2];

			printf("%d\n", s2);
			fprintf(fp2, "%d\n", pos2);
		}

		printf("%d\n", pos2);

	}

	//subquery 3

	for(k=1; k<=10; k++){

		r = rand()%10 +1;
		printf("Random integer number: %d\n", r);

		if(r>7){

			pos_h = r + 1;
			s3 = rw[pos_h];

			printf("%d\n", s3);
			h++;
			
			printf("%d\n", pos_h);
		}
		else{ // r<7

			pos_t = r - 1;
			s4 = rw[pos_t];

			printf("%d\n", s4);
			t++;
			
			printf("%d\n", pos_t);
		}
	}
	
	// variance - mean for single position

	for(i=0; i<=100; i++){
		
		// 1. variance
		
		sum = sum + pos1;
		sqdiff = sqdiff + (pos1 - m) * (pos1 - m);

		v = sqdiff/100;

		printf("%f\n", v);

		// 2. mean

		sum = sum + pos1;
		m = sum/100;
		printf("%f\n", m);

	}

	return 0;
}
