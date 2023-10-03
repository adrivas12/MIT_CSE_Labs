//2. Write a program to print out the complete stat structure of a file.

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


char *fdate(char*str, time_t val)
{
	strftime(str, 36, "%d.%m.%Y %H:%M:%S", localtime(&val)); 
	return str; 
}
int main(int argc, char *argv[])
{
	struct stat sb; 
	if(argc<2)
	{
		printf("Insufficient arguments\n" );
		return 1; 
	}
	int ret; 
	char date[36]; 
	ret=stat(argv[1], &sb); 
	if(ret)
	{
		perror("stat"); 
		return 1; 
	}
	printf("ID of device: %ld\n", sb.st_dev); 
	printf("INO number is: %lu\n", sb.st_ino); 
	printf("File Mode: %hu\n", sb.st_mode); 
	printf("number of hard links: %ld\n", sb.st_nlink); 
	printf("User ID: %d\n", sb.st_uid); 
	printf("Group owner: %d\n", sb.st_gid); 
	printf("File size: %ld\n", sb.st_size); 
	printf("Blocksize: %ld\n", sb.st_blksize); 
	printf("Number of Blocks: %ld\n", sb.st_blocks); 
	printf("last access time: %s\n", fdate(date, sb.st_atime)); 
	printf("last modification time: %s\n", fdate(date, sb.st_mtime));
	printf("last change time: %s\n", fdate(date, sb.st_ctime)); 

	DIR *dp; 
	struct dirent *entry; 
	struct stat statbuf; 
	if((dp=opendir("."))==NULL)
	{
			printf("Cannot open directory\n"); 
			return 0; 
	}
	chdir("."); 
	while((entry=readdir(dp))!=NULL)
	{
		lstat(entry->d_name,&statbuf);
 
        if(!S_ISDIR(statbuf.st_mode))
        {
            if(strcmp(entry->d_name,argv[1])==0)
            {
                printf("Permissions\t");
                printf( (S_ISDIR(statbuf.st_mode)) ? "d" : "-");
                printf( (statbuf.st_mode & S_IRUSR) ? "r" : "-");
                printf( (statbuf.st_mode & S_IWUSR) ? "w" : "-");
                printf( (statbuf.st_mode & S_IXUSR) ? "x" : "-");
                printf( (statbuf.st_mode & S_IRGRP) ? "r" : "-");
                printf( (statbuf.st_mode & S_IWGRP) ? "w" : "-");
                printf( (statbuf.st_mode & S_IXGRP) ? "x" : "-");
                printf( (statbuf.st_mode & S_IROTH) ? "r" : "-");
                printf( (statbuf.st_mode & S_IWOTH) ? "w" : "-");
                printf( (statbuf.st_mode & S_IXOTH) ? "x" : "-");
                printf("\n\n");
            }
        }
	}
}