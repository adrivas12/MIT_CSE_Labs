/*Write a program to print the lines of a file that contain a word given as the program
argument (a simple version of grep UNIX utility).*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char ch[100], ch1; 
	int sfd,k=0, i=0; 
	if(argc!=3)
	{
		printf("Invalid number of inputs\n"); 
		exit(1); 
	}
	if((sfd=open(argv[2], O_RDONLY))==-1)
	{
		printf("File not found\n"); 
		exit(1); 
	}
	while((read(sfd, &ch1, 1))>0)
	{
		if(ch1!='\n')
		{
			ch[i]=ch1; 
			i++; 
		}
		else
		{
			k++; 
			ch[i]='\0'; 
			i=0; 
			if(strstr(ch, argv[1])!=NULL)
			{
				printf("Line: %d \t %s\n", k, ch); 
			}
		}
	}
	exit(0); 
}