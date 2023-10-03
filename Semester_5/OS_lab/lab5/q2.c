//2. Demonstrate creation, writing to, and reading from a pipe.

#include "PreProcessorD.h"

int main(int argc, char *argv[])
{
	int n, fd[2];
	char buf[1025];
	char *data = "hello, this is sample data from lab5";
	pipe(fd);
	write(fd[1], data, strlen(data));
	if ((n = read(fd[0], buf, 1024)) >= 0) 
	{
		buf[n] = 0;
		/* terminate the string */
		printf("Read %d bytes from the pipe: \n\"%s\"\n", n, buf);
	}
	else
		perror("Read");
	exit(0);
}