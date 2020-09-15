#include <stdint.h>

int32_t bitcount(uint32_t x) {
	int count = 0;  // 10100111000 & 10100110111 = 10100110000
	while (x) {
		x = x & (x - 1);
		count++;
	}
	return count;
}


int main() {
	uint32_t x = 87124791;

	// 24 << 2    11000 << 2   1100000
	// 24 >> 2    110
	// & 1101 0100  0100 

	for (uint32_t i = 0; i < 32; i++) {
		printf("%d", ((1 << i) & x) >> i);
	}
	printf("\n");
}
