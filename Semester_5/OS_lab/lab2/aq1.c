/*Write a program that will only list subdirectories in alphabetical order.*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(void)
{
	struct dirent **entry;
	struct stat statbuf; 
	int n = scandir(".", &entry, 0, alphasort);
	if (n < 0)
		printf("Error in Scandir\n");
	else 
	{
		for(int i=0; i<n; i++) 
		{
			lstat(entry[i]->d_name, &statbuf);
			if(S_ISDIR(statbuf.st_mode))
			{
				if(strcmp(".", entry[i]->d_name)!=0 && strcmp("..", entry[i]->d_name)!=0)
				{
					printf("%s\n", entry[i]->d_name);
				}
			}
			free(entry[i]);
		}
	free(entry);
	}
}