#include <stdio.h>
#include <stdlib.h>

extern double
calc(double A, double B, double C, int D);

int main() {
	double* A = (double*)aligned_alloc(16, sizeof(double));
	double* B = (double*)aligned_alloc(16, sizeof(double));
	double* C = (double*)aligned_alloc(16, sizeof(double));
	int* D = (int*)aligned_alloc(16, sizeof(int));

	*A = 1.2, *B = 2.8, *C = 1;
	*D = 1;

	for (int i = 0; i < 1e9; ++i) {
		calc(*A, *B, *C, *D);
	}
}
