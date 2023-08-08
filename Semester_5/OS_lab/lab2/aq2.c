/*Write a program that allows the user to remove any or all of the files in a current
working directory. The name of the file should appear followed by a prompt as to
whether it should be removed.*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

void main()
{
	struct dirent **entry;
	struct stat statbuf; 
	char file[];
	printf("Enter the file you want to delete: \n");
	scanf("%s", file); 
	
}