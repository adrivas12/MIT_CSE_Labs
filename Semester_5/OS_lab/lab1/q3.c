//Demonstrate the use of different conversion specifiers and resulting output to allow the items to be printed.

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <errno.h>

int main()
{
	int a=10;
	float b=3.2;
	char c= 'k';
	char str[]="MIT college"; 

	printf("a=%d, b=%.3f, c=%c, str=%s hexadecimal for a=%x", a, b, c, str, a); 

	errno=EPERM;
	printf("Error Access Errono= %m\n"); 
}
