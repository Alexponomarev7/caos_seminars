#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

void login(int fd) {
	char buffer[1024];
	char x = 0;

	read(fd, buffer, 1056);

	// procceed password
	int64_t total = 0;
	for (int i = 0; i <	1024; ++i) {
		total += (int64_t)buffer[i] * i * total;
	}

	total += rand();

	if (total == 1592) {
		printf("YOU HACKED ME!");
		x = 1;
	}

	if (x != 0) {
		printf("WIN!\n");
	}
}

int main() {
	login(STDIN_FILENO);
	return 0;
}
