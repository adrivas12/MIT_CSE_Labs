/*Create a zombie (defunct) child process (a child with exit() call, but no
corresponding wait() in the sleeping parent) and allow the init process to adopt it
(after parent terminates). Run the process as a background process and run the “ps”
command.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	pid=fork(); 
	int status; 
	if(pid==-1)
		printf("ERROR child not created\n");
	else if(pid==0)   //child process
	{
		printf("Child process\n"); 
		exit(0); 
	}
	else
	{
		sleep(5); 
		printf("Parent process\n");
		printf("child returned %d\n", status); 
	}
}