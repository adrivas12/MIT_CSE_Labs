#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Smallest(int *p, int *q, int x[100], int n)
{
	int i;
	q = &x[0];
	for (i = 1; i<n; i++)
	{
		p = &x[i];
		if(p<q)
		{
			q = p;
		}
	}
	return *q;
}


int main()
{
	int i, n, x[100];
	int *p, *q;
	printf("Enter the number of elements in the array : ");
	scanf("%d", &n);
	printf("Enter the elements of the array \n");
	for(i =0; i<n; i++)
	{
		scanf("%d", &x[i]);
	}
	printf("The smallest element in the array is %d ", Smallest(p, q, x, n));
	return 0;
}