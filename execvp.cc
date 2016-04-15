#include <stdio.h>
#include <unistd.h>//open,dup2
#include <fcntl.h>//O_WRONLY

int main() {
	int fd = open("/dev/null", O_WRONLY);
	//dup2(fd, 1);//stdout
	dup2(fd, 2);//stderr
	close(fd);
	char *argv[] = {"ls", "-al","/tmp", NULL};
	execvp("ls", argv);
}
