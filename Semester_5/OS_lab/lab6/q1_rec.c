/*Process A wants to send a number to Process B. Once received, Process B has to check
whether the number is palindrome or not. Write a C program to implement this
interprocess communication using a message queue.*/
//Process B (receiver)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st
{
	long int my_msg_type; 
	int some_text; 
};
int isPalindrome(int n)
{
	int r,sum=0,temp;   
	temp=n;    
	while(n>0)    
	{    
		r=n%10;    
		sum=(sum*10)+r;    
		n=n/10;    
	}    
	if(temp==sum)    
		return 1;     
	return 0;  

}
int main()
{
	int running =1; 
	int msgid; 
	struct my_msg_st some_data; 
	long int msg_to_receive=0; 
	msgid=msgget((key_t)1234, 0666 | IPC_CREAT); 
	if(msgid==-1)
	{
		fprintf(stderr, "msgget failed with error: %d\n",errno );
		exit(EXIT_FAILURE); 
	}
	while(running)
	{
		if(msgrcv(msgid, (void *)&some_data, BUFSIZ,msg_to_receive,0)==-1)
		{
			fprintf(stderr, "msgrcv failed with error: %d\n", errno); 
			exit(EXIT_FAILURE); 
		}
		if(some_data.some_text==-1)
			running=0; 
		//printf("You wrote: %d", some_data.some_text); 
		if(isPalindrome(some_data.some_text)==1)
			printf("%d is a Palindrome\n", some_data.some_text); 
		else 
			printf("%d is not a Palindrome\n", some_data.some_text); 


	}
	if(msgctl(msgid, IPC_RMID, 0)==-1)
	{
		fprintf(stderr, "msgctl(IPC_RMID)failed\n"); 
		exit(EXIT_FAILURE); 
	}
	exit(EXIT_FAILURE); 
}