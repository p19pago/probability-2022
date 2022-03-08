#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
	
	#define N 10
	
	int i=0;
	double result;
	
	// separate counters for each decimal group
	int c1;
	int c2;
	int c3;
	int c4;
	int c5;
	int c6;
	int c7;
	int c8;
	int c9;
	int c10;
		
	for(i=1; i<=N; i++){
		
		result = (double) rand()/RAND_MAX;
		printf("Double value is: %f\n", result);
		
		if (result>=0.0 && result <0.1){
			c1++;
		}
		else if (result>=0.1 && result<0.2){
			c2++;
		}
		else if (result>=0.2 && result<0.3){
			c3++;
		}
		else if (result>=0.3 && result<0.4){
			c4++;
		}
		else if (result>=0.4 && result<0.5){
			c5++;
		}
		else if (result>=0.5 && result<0.6){
			c6++;
		}
		else if (result>=0.6 && result<0.7){
			c7++;
		}
		else if (result>=0.7 && result<0.8){
			c8++;
		}
		else if (result>=0.8 && result<0.9){
			c9++;
		}
		else if (result>=0.9 && result<1.0){
			c10++;
		}
	}
	
	return 0;
}
