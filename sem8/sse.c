#include <stdio.h>
#include <stdlib.h>
#include <smmintrin.h>

int main() {
	float  *arr1, *arr2;

	// Your codes goes here
	

	__m128 f1 = _mm_load_ps(arr1);
	__m128 f2 = _mm_load_ps(arr2);

	// Your codes goes here 
	_mm_dp_ps
}
