/*Write a C program to load the binary executable of the previous program in a child
process using the exec system call.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid; 
	pid=fork(); 
	if(pid<0)
	{
		fprintf(stderr, "Fork Failed"); 
		exit(-1); 
	}
	else if(pid==0)
	{
		execlp("./q1", "q1", (char *)0); 
	}
	else 
	{
		wait(NULL); 
		printf("Child Complete\n"); 
		exit(0); 
	}
	return 0 ;
}