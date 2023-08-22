/*Write a program to create a child process. Display the process IDs of the process,
parent and child (if any) in both the parent and child processes.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	pid=fork(); 
	if(pid==-1)
		printf("ERROR child not created\n");
	else if(pid==0)    //child process
	{
		printf("Child: \n"); 
		printf("Process ID: %d\n", getpid());
		printf("Process ID of parent: %d\n\n", getppid()); 
		exit(0); 
	}
	else			   //parent process
	{
		wait(NULL); 
		printf("Parent: \n"); 
		printf("Process id: %d\n", getpid()); 
		printf("Process ID of parent: %d\n", getppid()); 
		printf("Process ID of child: %d\n", pid); 
	}
}