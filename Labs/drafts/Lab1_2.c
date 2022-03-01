#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

	for(int i=1; i<=10; i++){
		printf("Random number value is: %d \n", rand());
	}
	
    return 0;
}