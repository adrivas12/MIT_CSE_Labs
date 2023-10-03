/*4. Write a program to create a new soft link to an existing file and unlink the same.
Accept the old path as input and print the newpath.*/

#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include <inttypes.h>
#include<stdlib.h>

void main(int argc, char* argv[])
{
    int l=symlink(argv[1], argv[2]); 
    int s=unlink(argv[1]); 
}