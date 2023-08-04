#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Smallest(int *p,int *q, int x[100], int n)
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
int ptp(int **pp1,int *p1,int a)
{
	p1 = &a; 
	pp1 = &p1;

	printf("\nInt a = %d , Address = %p", a, &a);
	printf("\nPointer to int value = %p, Address = %p\n", p1 , &p1);
	printf("Pointer to pointer to int pp value = %p, address = %p \n", pp1, &pp1);
}


int main()
{
	int i, n, x[100], a;
	int *p, *q, *p1, **pp1;
	printf("Enter the number of elements in the array : ");
	scanf("%d", &n);
	printf("Enter the elements of the array \n");
	for(i =0; i<n; i++)
	{
		scanf("%d", &x[i]);
	}
	printf("The smallest element in the array is %d \n", Smallest(p, q, x, n));
	printf("Enter an element: ");
	scanf("%d", &a);

	ptp(pp1, p1, a);
	return 0;
}
