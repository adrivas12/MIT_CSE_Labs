/*Implement a parent process, which sends an English alphabet to a child process
using shared memory. The child process responds with the next English alphabet
to the parent. The parent displays the reply from the Child.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

struct shared_use_st
{
	char alphabet; 
};
int main()
{
	void *shared_memory=(void*)0; 
	struct shared_use_st *shared_stuff; 
	char alphatosend; 
	pid_t pid; 
	int status; 
	int smid=shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT); 
	if(smid==-1)
	{
		printf("shmget failed!"); 
		exit(EXIT_FAILURE); 
	}
	shared_memory=shmat(smid, (void*)0, 0); 
	if(shared_memory==(void*)-1)
	{
		printf("shmat failed!\n"); 
		exit(EXIT_FAILURE);
	}
	printf("Memory attached at %X\n", (int)shared_memory); 
	shared_stuff=(struct shared_use_st*)shared_memory; 
	printf("Enter an alphabet: "); 
	scanf("%c", &alphatosend); 
	shared_stuff->alphabet=alphatosend; 
	printf("\nParent process wrote to shared memory\n"); 
	pid=fork(); 
	if(pid==0)
	{
		printf("\nInside child process...\n"); 
		char alphabet=shared_stuff->alphabet; 
		if(alphabet=='z')
		{
			alphabet='a'; 
		}
		else if(alphabet=='Z')
		{
			alphabet='A'; 
		}
		else 
		alphabet=(char)((int)alphabet+1); 
		shared_stuff->alphabet=alphabet; 
		printf("Child Process updated shared memory\n"); 

	}
	else 
	{
		wait(&status); 
		printf("Inside parent process....\n"); 
		printf("Alphabet in shared memory: %c\n", shared_stuff->alphabet); 
	}
}