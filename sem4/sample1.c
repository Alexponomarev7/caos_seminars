#include <stdio.h>
#include <stdint.h>

typedef union {
	float real_value;
	uint32_t uint_value;
} real_or_uint;

int main() {
	real_or_uint number;
	number.real_value = 3.1415;

	// find a bug!
	for (uint64_t i = 0; i < 32; i++) { // 0101 
		if (i == 1) printf(" ");
		if (i == 9) printf(" ");
		printf("%lld", ((1ULL << (31 - i)) & number.uint_value) >> (31 - i));
		
	}
	printf("\n");
	return 0;
}
