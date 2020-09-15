#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	int32_t* y_heap = (int32_t*)malloc(sizeof(int32_t));

        *y_heap = 10;
	printf("Addres: %p, Value: %d\n", y_heap, *y_heap);
	free(y_heap);

	int x, y;
	printf("%p %p\n", &x, &y);
}
