#include <stdio.h>
#include <stdint.h>

struct A {
	char x;
	int64_t y;
};

int main() {
	printf("%d", sizeof(struct A));
}

