/*1. Write a producer and consumer program in C using the FIFO queue. The producer
should write a set of 4 integers into the FIFO queue and the consumer should
display the 4 integers.*/

#include "PreProcessorD.h"

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF
#define TEN_MEG (1024*1024*10)

int main()
{
	int pipe_fd, res, open_mode = O_WRONLY, bytes_sent = 0; 
	char buffer[BUFFER_SIZE+1]; 
	if(access(FIFO_NAME, F_OK)==-1)
	{
		res= mkfifo(FIFO_NAME, 0777); 
		if(res!=0)
		{
			fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME); 
			exit(EXIT_FAILURE); 
		}
	}
	printf("Process %d opening FIFO O_WRONLY\n", getpid()); 
	pipe_fd= open(FIFO_NAME, open_mode);

	//printf("Process %d result %d \n", getpid(), pipe_fd); 
	if(pipe_fd!=-1)
	{
		printf("Enter 4 numbers: \n");
		while(bytes_sent<4)
		{
			printf("%d:", bytes_sent+1); 
			scanf("%s", buffer); 
			res=write(pipe_fd, buffer, BUFFER_SIZE); 
			if(res==-1)
			{
				fprintf(stderr, "Write error on pipe\n" );
				exit(EXIT_FAILURE); 
			}
			bytes_sent++;
		}
		(void)close(pipe_fd); 
	}
	else
	{
		exit(EXIT_FAILURE); 
	}
	printf("Process %d finished \n", getpid()); 
	exit(EXIT_FAILURE); 
}