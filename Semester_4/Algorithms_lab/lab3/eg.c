#include<stdio.h>
#include<stdlib.h>
void SelectionSort(int *a, unsigned int n)
{
	unsigned int min; 
	int temp; 
	int opcount=0; 
	for(int i=0; i<n-1; i++)
	{
		min=i; 
		for(int j=i+1; j<n; j++)
		{
			++opcount; 
			if(a[j]<a[min])
				min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp; 
	}
	printf("\nopcount: %d", opcount); 
}
int main()
{
	int *a; 
	int n=5; 
	for(int j=0; j<4; j++)
	{
		a=(int*)malloc(sizeof(int)*n); 
		for(int k=0; k<n; k++)
			a[k]=n-k;
		printf("Elements are: "); 
		for(int i=0; i<n; i++)
		{
			printf("%d", a[i]); 
		}
		SelectionSort(a, n); 
		printf("\nElements after selection sort ");
		for(int i=0; i<n; i++)
			printf("%d", a[i]); 
		printf("\n"); 
		free(a); 
		n=n+5; 
	}
	return 0; 
}