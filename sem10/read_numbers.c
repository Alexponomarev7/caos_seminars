#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#include <unistd.h>

ssize_t Read(int fd, void* ptr, ssize_t count) {
	ssize_t total = 0, cur = 0;
	for (; total != count; total += cur) {
		cur = read(fd, ptr + total, count - total);
		if (cur == -1) {
			perror("Read");
			return -1;
		}		

		if (cur == 0) {
			break;
		}

		total += cur;
	}

	printf("total %d\n", total);

	return total;
}

int main(int argc, char** argv) {
	int fd = open(argv[1], O_RDONLY);

	if (fd == -1) {
		perror("Open");
		return 1;
	}

	int buffer[1024];
	ssize_t total;
	while (total = Read(fd, &buffer, sizeof(int) * 1024)) {
		if (total == -1) {
			return 1;
		}

		for (int i = 0; i < total / sizeof(int); ++i) {
			printf("%d ", buffer[i]);
		}
	} 

	close(fd);

	return 0;
}
