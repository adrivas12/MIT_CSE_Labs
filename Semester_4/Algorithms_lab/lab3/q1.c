#include<stdio.h>
#include<stdlib.h>
void BubbleSort(int *a, unsigned int n)
{
	int temp, flag=0; 
	int opcount=0; 
	for(int i=0; i<n-1; i++)
	{
		flag=1;
		for(int j=0; j<n-i-1; j++)
		{
			opcount++; 
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp; 
				flag=0;
			}	
		}
		//opcount+=j; 
		if(flag==1)
			break;
	}
	printf("\nOpcount: %d", opcount); 
}
int main()
{
	int *a; 
	int n=5; 
	for(int j=0; j<4; j++)
	{
		a=(int*)malloc(sizeof(int)*n); 
		//for(int k=0; k<n; k++)
		//	a[k]=n-k; 
		printf("\nEnter Elements: ");
		for(int i=0; i<n; i++)
		{
			scanf("%d", &a[i]); 
		}
		printf("Elements are: "); 
		for(int i=0; i<n; i++)
		{
			printf("%d ", a[i]); 
		}
		BubbleSort(a, n); 
		printf("\nElements after bubble sort ");
		for(int i=0; i<n; i++)
			printf("%d", a[i]); 
		printf("\n"); 
		free(a); 
		n=n+5; 
	}
	return 0; 
}