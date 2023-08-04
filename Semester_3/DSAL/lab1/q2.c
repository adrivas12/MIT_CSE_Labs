#include<stdio.h>

void Lsearch(int arr[10], int n, int ele)
{
	int i, flag=0; 
	for(i = 0; i<n; i++)
	{
		if(arr[i] == ele)
		{
			//printf("%d", i);
			flag = 1;
			break;
		}
	}
	if(flag == 1)
		printf("Element found at position %d", i);
	else 
		printf("Element not found");

}

int main()
{
	int arr[10];
	int i, n, ele;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("Enter the elements of the array: ");
	for(i = 0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter the element to be found : ");
	scanf("%d", &ele);
	Lsearch(arr, n, ele);
}