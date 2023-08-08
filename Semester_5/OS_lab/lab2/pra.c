/*Start with the appropriate headers and then a function, printdir , which prints out the
current directory. It will recurse for subdirectories using the depth parameter for
indentation.*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

void printdir(char *dir, int depth)
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
		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(".", entry->d_name)==0 || strcmp("..", entry->d_name)==0)
				continue; 
			printf("%*s%s\n", depth, "", entry->d_name); 
			printdir(entry->d_name, depth+4); 
		}
		else 
		printf("%*s%s\n", depth, "", entry->d_name); 

	}
	chdir(".."); 
	closedir(dp); 
}

int main()
{
	printdir("folder1", 3); 
	return 0; 
}