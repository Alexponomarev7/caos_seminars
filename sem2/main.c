#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern int32_t x;

int main() {
	int32_t y = ~x + 1; // 0101 -> 1010 + 1 -> 1011	
	int32_t* y_heap = (int32_t*)malloc(sizeof(int32_t)); // brk


	char buffer[1024];

	uint8_t x1 = 255, y1 = 255;
	printf("%d", x1 + y1);
	
	*y_heap = 10;
	printf("Addres: %p, Value: %d\n", y_heap, *y_heap);

	printf("%d %d\n", x, y);
}
