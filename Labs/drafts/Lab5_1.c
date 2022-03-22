#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
	srand(time(NULL));
	
	int result = 0;
	
	int i;
	int j;
	int k;
	int s; //counter for Success
	
	int A[10]= {0};
	
	for(i=1; i<=100; i++){ //first loop
	
		int c; //generic counter
		
		for(j=1; j<=10; j++){ //second loop
			A[j] = rand()%2;
			printf("%d\n", A[j]);
		}
		
		for(k=0; k<3; k++){
			
			if(A[k]==1){
					c++;
					printf("1\n");
			}
			else{
					printf("0\n");
			}
			
			if (c==3){
				result = result + 1;
			}
		}
	}
	
	printf("%d\n", result);
	
return 0;
}
