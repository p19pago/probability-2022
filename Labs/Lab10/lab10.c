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

int h = 0; // counter for Heads
int t = 0; // counter for Tails
int r; //expected result for heads/tails experiment
int k; //counter for third loop

int pos_h; //position for Heads
int pos_t; //position for Tails

// variance - mean
double m; //variable for mean
double v; //variable for variance
int sum = 0;
double sqdiff = 0;

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
	
	for (i<0; i<=1000; i++){
		x = rand()%2;
		s50 = rw[x];
		
		if (x==1){
			s50 = s50 + 1;
		}
		if (x==0){
			s50 = s50 - 1;
		}
		
		d50[s50]++;
		c50++;
	}
	
	printf("%d", c50);
	
	
	FILE *fp50;
	fp50 = fopen("walkers50.txt", "w");
	fprintf(fp50, "%d\n", d50[s50]);
	fprintf(fp50, "%d\n", c50);
	
	//100 walkers - separate loop
	c100 = 0;
	
	for (i<0; i<=1000; i++){
		x = rand()%2;
		s100 = rw[x];
		
		if (x==1){
			s100 = s100 + 1;
		}
		if (x==0){
			s100 = s100 - 1;
		}
		
		d100[s100]++;
		c100++;
	}
	
	printf("%d", c100);
	//writing into a .txt file for 100 walkers
	
	FILE *fp100;
	fp100 = fopen("walkers100.txt", "w");
	fprintf(fp100, "%d\n", d100[s100]);
	fprintf(fp100, "%d\n", c100);
	
	//500 walkers - separate loop
	c500 = 0;
	
	for (i<0; i<=1000; i++){
		x = rand()%2;
		s500 = rw[x];
		
		if (x==1){
			s500 = s500 + 1;
			c500++;
		}
		if (x==0){
			s500 = s500 - 1;
			c500++;
		}
		
		d500[s500]++;
	}
	
	printf("%d", c500);
	//writing into a .txt file for 500 walkers
	
	FILE *fp500;
	fp500 = fopen("walkers500.txt", "w");
	fprintf(fp500, "%d\n", d500[s500]);
	fprintf(fp500, "%d\n", c500);
	
	//1000 walkers - separate loop
	c1000 = 0;
	
	for (i<0; i<=1000; i++){
		x = rand()%2;
		s1000 = rw[x];
		
		if (x==1){
			s1000 = s1000 + 1;
		}
		if (x==0){
			s1000 = s1000 - 1;
		}
		
		d1000[s1000]++;
		c1000++;
	}
	
	printf("%d", c1000);
	//writing into a .txt file for 1000 walkers
	
	FILE *fp1000;
	fp1000 = fopen("walkers1000.txt", "w");
	fprintf(fp1000, "%d\n", d1000[s1000]);
	fprintf(fp1000, "%d\n", c1000);
	
	//subquery 2
	for(i=0; i<=1000; i++){
		x = rand()%1000+1;
		printf("Random number result is: %d\n", x);
		
		if(x>5){

			pos1 = x + 1;
			s2 = rw[pos2];

			printf("%d\n", s2);

		}

		if(x<5){

			pos1 = x - 1;
			s2 = rw[pos2];

			printf("%d\n", s2);

		}
		
		FILE *fp2;
		fp2 = fopen("walkers2_lab10.txt", "w");
		fprintf(fp2, "%d\n", pos2);
		
		FILE *fp;
		fp = fopen("walkers_lab10.txt", "w");
		fprintf(fp, "%d\n", pos1);
		fprintf(fp, "%d\n", pos2);
	}
	
	return 0;
}
