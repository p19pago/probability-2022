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

int s10;
int s50;
int s100;
int s500;
int s1000;

// variables for subquery 3
// variance - mean

//position 1
double mn1; //variable for mean
double var1; //variable for variance
int sum1 = 0;
double sqdiff1 = 0;

//position 2
double mn2; //variable for mean
double var2; //variable for variance
int sum2 = 0;
double sqdiff2 = 0;

//generic (attached to variables off previous positions)
double mn; //mean
double var; //variance
int sum;
double sqdiff;

//frequency tables
int d10[1000]={0};
int d50[1000]={0};
int d100[1000]={0};
int d500[1000]={0};
int d1000[1000]={0};

//counters
int c10 = 0;
int c50 = 0;
int c100 = 0;
int c500 = 0;
int c1000 = 0;

int main(int argc, char** argv){
	
	FILE *fp1;
	fp1 = fopen("walkers1_lab10.txt", "w");
	
	for(i=0; i<=1000; i++){
		x = rand()%1000+1;
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
	}
	
	//10 walkers - separate loop
	//writing into a .txt file for 10 walkers
	
	FILE *fp10;
	fp10 = fopen("walkers10.txt", "w");
	
	for (i<0; i<=1000; i++){
		x = rand()%2;
		s10 = rw[x];
		
		if (x==1){
			s10 = s10 + 1;
		}
		if (x==0){
			s10 = s10 - 1;
		}
		printf("%d", s10);
		
		d10[s10]++;
		c10++;
		
		fprintf(fp10, "%d\n", d10[s10]);
		fprintf(fp10, "%d\n", c10);
	}
	
	//50 walkers - separate loop
	//writing into a .txt file for 50 walkers
	
	FILE *fp50;
	fp50 = fopen("walkers50.txt", "w");
	
	for (i<0; i<=1000; i++){
		x = rand()%2;
		s50 = rw[x];
		
		if (x==1){
			s50 = s50 + 1;
		}
		if (x==0){
			s50 = s50 - 1;
		}
		printf("%d", s50);
		
		d50[s50]++;
		c50++;
		
		fprintf(fp50, "%d\n", d50[s50]);
		fprintf(fp50, "%d\n", c50);
	}
	
	//100 walkers - separate loop
	//writing into a .txt file for 100 walkers
	
	FILE *fp100;
	fp100 = fopen("walkers100.txt", "w");
	
	for (i<0; i<=1000; i++){
		x = rand()%2;
		s100 = rw[x];
		
		if (x==1){
			s100 = s100 + 1;
		}
		if (x==0){
			s100 = s100 - 1;
		}
		printf("%d", s100);
		
		d100[s100]++;
		c100++;
		
		fprintf(fp100, "%d\n", d100[s100]);
		fprintf(fp100, "%d\n", c100);
	}
	
	//500 walkers - separate loop
	//writing into a .txt file for 500 walkers
	
	FILE *fp500;
	fp500 = fopen("walkers500.txt", "w");
	
	for (i<0; i<=1000; i++){
		x = rand()%2;
		s500 = rw[x];
		
		if (x==1){
			s500 = s500 + 1;
		}
		if (x==0){
			s500 = s500 - 1;
		}
		printf("%d", s500);
		
		d500[s500]++;
		c500++;
		
		fprintf(fp500, "%d\n", d500[s500]);
		fprintf(fp500, "%d\n", c500);	
	}
	
	//1000 walkers - separate loop
	//writing into a .txt file for 1000 walkers
	
	FILE *fp1000;
	fp1000 = fopen("walkers1000.txt", "w");
	
	for (i<0; i<=1000; i++){
		x = rand()%2;
		s1000 = rw[x];
		
		if (x==1){
			s1000 = s1000 + 1;
		}
		if (x==0){
			s1000 = s1000 - 1;
		}
		printf("%d", s1000);
		
		d1000[s1000]++;
		c1000++;
		
		fprintf(fp1000, "%d\n", d1000[s1000]);
		fprintf(fp1000, "%d\n", c1000);
	}
	
	//subquery 2
	
	//writing into a different .txt file for position 2.
	FILE *fp2;
	fp2 = fopen("walkers2_lab10.txt", "w");
	
	//writing into a different .txt file for both positions 1 and 2.
	FILE *fp;
	fp = fopen("walkers_lab10.txt", "w");
	
	for(j=0; j<=1000; j++){
		x = rand()%1000+1;
		printf("Random number result is: %d\n", x);
		
		if(x>5){
			pos1 = x + 1;
			s2 = rw[pos2];
			
			printf("%d\n", s2);
			fprintf(fp2, "%d\n", pos2);
		}

		if(x<5){
			pos1 = x - 1;
			s2 = rw[pos2];

			printf("%d\n", s2);
			fprintf(fp2, "%d\n", pos2);
		}	
	}
	
	fprintf(fp, "%d\n", pos1);
	fprintf(fp, "%d\n", pos2);
	
	//subquery 3
	//for both positions -- not heads-or tails values
	
	for(i=1; i<=1000; i++){

		x = rand()%1000+1;
		printf("Random number result is: %d\n", x);

		// variance - mean
		// 1. variance
		
		//for position 1
		sum1 = sum1 + pos1;
		sqdiff1 = sqdiff1 + (pos1 - mn1) * (pos1 + mn1);
		var1 = sqdiff1/1000;
		printf("%f\n", var1);

		//for position 2
		sum2 = sum2 + pos2;
		sqdiff2 = sqdiff2 + (pos2 - mn2) * (pos2 + mn2);
		var2 = sqdiff/1000;
		printf("%f\n", var2);

		// 2. mean
		
		//for position 1
		sum1 = sum1 + pos1;
		mn1 = sum1/1000;
		printf("%f\n", mn1);

		//for position 2
		sum2 = sum2 + pos2;
		mn2 = sum2/1000;
		printf("%f\n", mn2);
	}
	
	//generic
	
	sum = sum1 + sum2;
	sqdiff = sqdiff1 - sqdiff2;
	var = sqdiff/1000;
	mn = sum/1000;
	
	printf("%d\n", sum);
	printf("%f\n", sqdiff);
	printf("%f\n", var);
	printf("%f\n", mn);
	
	return 0;
}
