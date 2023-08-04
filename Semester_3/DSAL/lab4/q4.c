#include<stdio.h>
#include<stdlib.h>

int toha(int n, char from, char aux, char to)
{
	if(n==1)
	{
		printf("Move disk 1 form %c to %c\n", from, to);
		return 0;
	}
	else
	{
		toha(n-1, from, to, aux);
		printf("Move disk %d from %c to %c\n", n, from, to);
		toha(n-1, aux, from, to);
	}
}

void main()
{
	int n;
	printf("Enter the number of disks: ");
	scanf("%d", &n);
	toha(n, 'X', 'Y', 'Z');
}