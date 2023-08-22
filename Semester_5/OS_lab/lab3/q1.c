//Write a C program to block a parent process until the child completes using a wait

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	int status; 
	pid_t pid; 
	pid=fork(); 
	if(pid==-1)
		printf("ERROR child not created\n");
	else if(pid==0)   //child process
	{
		printf("Child Process\n"); 
		exit(0); 
	}
	else
	{
		wait(&status); 
		printf("Parent Process\n"); 
		printf("Child returned %d\n", status); 
	}
}