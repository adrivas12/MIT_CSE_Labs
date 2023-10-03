/*Write a multithreaded program that performs the sum of even numbers and odd
numbers in an input array. Create a separate thread to perform the sum of even
numbers and odd numbers. The parent thread has to wait until both the threads are
done.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *add_odd(void *args)
{
	int *arr=(int *)args; 
	int n=arr[0]; 
	int *res=(int *)malloc(sizeof(int)); 
	*res=0; 
	for(int i=1; i<=n; i++)
	{
		if(arr[i]&1)
			*res+=arr[i]; 
	}
	return (void*)res;
}
void *add_even(void *args)
{
	int *arr=(int *)args; 
	int n=arr[0]; 
	int *res=(int *)malloc(sizeof(int)); 
	*res=0; 
	for(int i=1; i<=n; i++)
	{
		if(!(arr[i]&1))
			*res+=arr[i]; 
	}
	return (void*)res;
}

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("Not enough arguments!\n"); 
		exit(EXIT_FAILURE); 
	}
	int n=argc-1;
	int *arr=(int *)calloc(n+1, sizeof(int)), *resEven, *resOdd; 
	arr[0]=n; 
	for(int i=0; i<n; i++)
		arr[i+1]=atoi(argv[i+1]); 

	pthread_t threadOdd, threadEven; 
	pthread_create(&threadOdd, 0, &add_odd, (void*)arr); 
	pthread_create(&threadEven, 0, &add_even, (void*)arr); 
	pthread_join(threadOdd, (void **)&resOdd); 
	pthread_join(threadEven, (void **)&resEven); 
	printf("The Sum of Even Numbers: %d\n", *resEven); 
	printf("The Sum of Odd Numbers: %d\n", *resOdd); 
	return 0; 
}