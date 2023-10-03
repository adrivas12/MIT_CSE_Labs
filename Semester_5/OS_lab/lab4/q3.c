/*3. Write a program to create a new hard link to an existing file and unlink the same.
Accept the old path as input and print the newpath.*/

#include <unistd.h>
#include <stdio.h>

void main(int argc, char* argv[])
{
    int l=link(argv[1], argv[2]); 
    int s=unlink(argv[1]); 
}