#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char** argv){

	// #define N 10000

	float a[10000];

	float y1;
	float y2;
	float y3;
	float y4;

	int i, j;

	srand(time(NULL));

	FILE *fp = fopen("functions_lab4_10000.txt", "w");

	for(i=0; i<10000; i++){
		a[i] = (float) rand()/RAND_MAX;
		printf("%f\n", a[i]);
	}

	for (j=0; j<10000; j++){
		printf("Random value is: %f\n", a[j]);

		y1 = log(1-a[j]);
		printf("The result is: %f\n", y1);

		y2 = pow(a[j], 2);
		printf("The result is: %f\n", y2);

		y3 = pow(a[j], 2) + pow(a[j+1], 2);
		printf("The result is: %f\n", y3);

		y4 = pow(a[j], 2) + pow(a[j+1], 2) + pow(a[j+2], 2) + pow(a[j+3], 2);
		printf("The result is: %f\n", y4);

	}

	fprintf(fp, "%d\n", y1);
	fprintf(fp, "%d\n", y2);
	fprintf(fp, "%d\n", y3);
	fprintf(fp, "%d\n", y4);

	fclose(fp);
	return 0;
}
