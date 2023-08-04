#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, n;
	int a[10000];
	for (i =0; i<=10000; i++)
	{
		n = (rand()%(200+1))+ (-100);
		a[10000] = n;
		printf("%d  ", a[10000]);
	}
}