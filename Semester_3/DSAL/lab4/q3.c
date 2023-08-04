#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int pali(char a[], int count)
{
	int len = strlen(a) - (count+1);
	if(a[count] == a[len])
	{
		if(count+1 == len || count == len)
		{
			printf("The entered word is a palindrome\n");
			return 0;
		}
		pali(a, count+1);
	}
	else
	{
		printf("The entered word is not a palindrome\n");
	}
	return 0;
}

void main()
{
	char a[30];
	printf("Enter a string: ");
	scanf("%s", a);

	pali(a, 0);
}