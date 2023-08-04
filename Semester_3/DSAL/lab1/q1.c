#include<stdio.h>

double Add(double arr[20], int n);

void main()
{
	double arr[20];
	int n;
	printf("Enter n \n");
	scanf("%d" , &n);
	printf("Enter the array elements \n");

	for(int i = 0; i<n; i++)
		scanf("%lf", &arr[i]);
	printf("The sum is %lf", Add(arr, n));
}

double Add(double arr[20], int n)
{
	double sum = 0; 
	for(int i = 0; i<n; i++)
	{
		sum+=arr[i];
	}
	return sum;
}