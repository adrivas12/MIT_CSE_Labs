/*1. Write a program to find the inode number of an existing file in a directory. Take the
input as a filename and print the inode number of the file.*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	struct stat sb; 
	int ret; 
	if(argc<2)
	{
		fprintf(stderr, "usage: %s\n", argv[0]);
		return 1; 
	}
	ret=stat(argv[1], &sb); 
	if(ret)
	{
		perror("stat"); 
		return 1; 
	}
	printf ("Inode number for %s is: %ld \n", argv[1], sb.st_ino);
	return 0; 
}