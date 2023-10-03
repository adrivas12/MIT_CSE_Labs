#include "PreProcessorD.h"

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF

int main()
{
	int pipe_fd, res, open_mode = O_RDONLY, n = 0, bytes_read=0;
	char buffer[BUFFER_SIZE + 1];
	memset(buffer, '\0', sizeof(buffer));
	printf("Process %d opening FIFO O_RDONLY\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);

	printf("Process %d result %d\n", getpid(), pipe_fd);
	if (pipe_fd != -1) 
	{
		do 
		{
			printf("%d: ", n+1); 
			res = read(pipe_fd, buffer, BUFFER_SIZE);
			printf("%s\n", buffer); 
			bytes_read += BUFFER_SIZE;
			n++; 
		} while (n <4);
		(void)close(pipe_fd);
	}
	else 
	{
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
	exit(EXIT_SUCCESS);
	return 0; 
}