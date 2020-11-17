#include <stdio.h>

extern int sum(int x, int y);

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", sum(x, y));
}
