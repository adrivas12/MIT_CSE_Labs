/*Write a program that allows the user to remove any or all of the files in a current
working directory. The name of the file should appear followed by a prompt as to
whether it should be removed.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("\nWrong number of arguments");
		exit(1);
	}
	
	DIR* directory = opendir(argv[1]);
	struct stat statbuf;
	struct dirent* entry;
	int option = 0;
	
	if(directory == NULL)
	{
		printf("\nCould not open directory");
		exit(1);
	}
	
	chdir(argv[1]);
	
	while((entry = readdir(directory)) != NULL)
	{
		lstat(entry->d_name, &statbuf);
		if(!S_ISDIR(statbuf.st_mode))
		{
			printf("\nDo you want to remove %s [1/0]: ", entry->d_name);
			scanf("%d", &option);
			if(!option)
				continue;
			else
			{
				char path[256];
				strcpy(path, argv[1]);
				strcat(path, "/");
				strcat(path, entry->d_name);
				printf("\n%s", path);
				remove(path);
			}	
		}
	}
}
