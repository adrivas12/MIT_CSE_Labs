#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Reverse(int n, int a[100], int *p)
{
	int i;
	p = &a[n-1];
	printf("The elements of the array in reverse order are : ");
	for(i =0; i<n; i++)
		printf("%d ", *p--);
}


int main()
{
	int i, n, *p, a[100];
	printf("Enter the number of integers of the array: \n");
	scanf("%d", &n);

	printf("Enter %d elements of the array : ", n);
	for(i =0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	Reverse(n, a, p);
	return 0;
}