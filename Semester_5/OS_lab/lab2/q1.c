/*Write a C program to emulate the ls -l UNIX command that prints all files in a
current directory and lists access privileges, etc. DO NOT simply exec ls -l from the
program.*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

void listfiles(char *dir)
{
	DIR *dp; 
	struct dirent *entry; 
	struct stat statbuf; 
	if((dp=opendir(dir))==NULL)
	{
		fprintf(stderr, "cannot open directory: %s\n", dir);
		return; 
	}
	chdir(dir);
	while((entry=readdir(dp))!=NULL)
	{
		lstat(entry->d_name, &statbuf);
		if(!S_ISDIR(statbuf.st_mode))
		{
			printf("%s\n", entry->d_name); 
		    printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
		    printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
		    printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
		    printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
		    printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
		    printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
		    printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
		    printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
		    printf((statbuf.st_mode & S_IXOTH) ? "x" : "-");
		    printf("\n\n");
		}
	}
	chdir(".."); 
	closedir(dp); 
}
int main()
{
	listfiles("."); 
	return 0; 
}