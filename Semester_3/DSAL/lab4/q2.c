#include<stdio.h>
#include<string.h>

int copy(char a[], char b[], int count)
{
	if(a[count] == '\0')
		return 0;
	b[count]=a[count];
	copy(a, b, count+1);
}

int main()
{
	char a[30], b[30];
	int count=0;
	printf("Enter the string to be copied: ");
	scanf("%s", a);

	copy(a, b, 0);
	printf("The copied value of the string is: %s\n", b);
}