#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



int main(int argc, char** argv){
	
	// variable declaration
	
	int i;
	int j;
	
	int rw[1000][1000]; //2D table used for random walk capture
	int pos; //position
	int s;
	
	int d; // stands for direction
	
	srand(time(NULL));
	for(i=0; i<=1000; i++){
		for (j=0; j<1000; j++){
				d = rand()%10+1;
				printf("Random number result is: %d\n", d);
				
				if (d=1){
					pos = rw[(j-1)+1, j-1];
					s = rw[pos];

				}
				else if (d=2){
					pos = rw[(j-1)-1, j-1];
					s = rw[pos];	
				}
				else if(d=3){
					pos = rw[j-1, (j-1)+1];
					s = rw[pos];
				}
				else if(d=4){ 
					pos = rw[j-1, (j-1)-1];
					s = rw[pos];
				}
				printf("%d\n", s);
		}
	}
	//code
	return 0;
}
