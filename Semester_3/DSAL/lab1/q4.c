#include<stdio.h>

int Second_largest(int x[], int i, int n)
{
	int first = x[0];
	int second = x[0];
	for(int i = 0; i<n; ++i)
	{
		if(first<x[i])
		{
			second = first;
			first = x[i];
		}
		else if(x[i] > second && x[i]!=first)
		{
			second = x[i];
		}
	}
	if( second == first)
		printf("There is no second largest ");
	else 
		printf("The second largest number if %d \n", second);
}

int main()
{
	int x[10];
	int i, n;
	printf("Enter the number of elements in the array \n");
	scanf("%d", &n);
	printf("Enter %d elements in the array : \n", n);
	for( i =0; i<n; i++)
	{
		scanf("%d", &x[i]);
	}
	Second_largest(x, i, n);
	return 0;
}