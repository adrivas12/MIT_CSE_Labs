#include <sys/types.h>
#include <sys/wait.h>

/*void main()
{
	int status; 
	pid_t pid; 
	pid=fork(); 
	if(pid==-1)
		printf("ERROR child not created\n");
	else if(pid==0)   //child process
	{
		printf("I'm the child\n"); 
		exit(0); 
	}
	else
	{
		wait(&status); 
		printf("I'm the parent\n"); 
		printf("child returned %d\n", status); 
	}
}*/

int main()
{
	fork(); 
	fork(); 
	fork(); 
	fork(); 
	printf("hi\n"); 
}