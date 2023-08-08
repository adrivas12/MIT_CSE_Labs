/*Write a program to list the files given as arguments, stopping every 20 lines until a
key is hit. (a simple version of more UNIX utility)*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char ch[100], ch2[100], ch1; 
	int fil1, fil2, k=0, i=0, m=0; 
	if(argc!=3)
	{
		printf("Invalid number of inputs\n"); 
		exit(1); 
	}
	if((fil1=open(argv[1], O_RDONLY))==-1)
	{
		printf("File 1 not found\n"); 
		exit(1); 
	}
	if((fil2=open(argv[2], O_RDONLY))==-1)
	{
		printf("File 2 not found\n"); 
		exit(1); 
	}
	while((read(fil1, &ch1, 1))>0)
	{
		if(ch1!='\n')
		{
			ch[i]=ch1; 
			i++;
		}
		else
		{
			k++; 
			m++; 
			ch[i]='\0'; 
			i=0; 
			printf("Line: %d \t %s\n", k, ch); 
			if(k==20)
			{
				fgetc(stdin); 
				k=0; 
			}
		}

	}
	close(fil1); 
	m=0; 
	while((read(fil2, &ch1, 1))>0)
	{
		if(ch1!='\n')
		{
			ch2[i]=ch1; 
			i++; 
		}
		else 
		{
			k++; 
			m++; 
			ch[i]='\0'; 
			i=0; 
			printf("Line: %d \t %s\n", k, ch2); 
			if(k==20)
			{
				fgetc(stdin); 
				k=0; 
			}
		}
	}
	exit(0); 
}