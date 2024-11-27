#include <stdio.h>
#include <stdlib.h>  
#include <time.h>   

extern float dotproduct(float *a, float *b, int n);

int main() {
	
    int n;
	int i;
	
    printf("Input n: ");
    scanf("%d", &n);

    float *a = malloc(n * sizeof(float));
    float *b = malloc(n * sizeof(float));

    srand(50);

    for (i = 0; i < n; i++) {
        a[i] = (float)(rand() % 1000) / 100.0; // Random float between 0.00 and 9.99
        b[i] = (float)(rand() % 1000) / 100.0; // Random float between 0.00 and 9.99
    }

    
    // Start clock
    
    clock_t start = clock();
    	
    float result = dotproduct(a, b, n);
	
	// End clock
	clock_t end = clock();
	double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
	
    printf("Dot product: %.2f\n", result);
	printf("Time taken to compute the dot product in assembly: %.6f seconds\n", time_taken);
	
    // Free the dynamically allocated memory
    
    free(a);
    free(b);

    return 0;
}
