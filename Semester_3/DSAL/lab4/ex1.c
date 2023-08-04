#include<stdio.h>
#include "ex1.h"

void main()
{
	int i, pos, a[30], n, item;
	printf("Enter number of items: ");
	scanf("%d", &n);
	printf("\nEnter the elements in ascending order: ");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("\nEnter the element to be searched: ");
	scanf("%d", &item);
	pos = bin_search(0, n-1, item, a);
	if(pos!=-1)
		printf("Item found at location %d", pos+1);
	else
		printf("Item not found");
}