#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  

int main(){
	
	int n;
	float dotproduct = 0.0;
	
	printf("Input: ");
	scanf("%d", &n);
	
  	float *a = malloc(n * sizeof(float)); 
    float *b = malloc(n * sizeof(float)); 
    
	int i;
	
    srand(50);

	clock_t start = clock();
	
    for (i = 0; i < n; i++) {
        a[i] = (float)(rand() % 1000) / 100.0; // Random float between 0.00 and 9.99
        b[i] = (float)(rand() % 1000) / 100.0; // Random float between 0.00 and 9.99
        dotproduct += a[i] * b[i];              
    }
	
	clock_t end = clock();
	double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
	
 	printf("Dot product: %.2f\n", dotproduct);
	printf("Time taken to compute the dot product in C: %.6f seconds\n", time_taken);
	
	return 0;
	
}
