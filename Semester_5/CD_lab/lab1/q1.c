//To count the number of lines and characters in a file 

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr1; 
	char filename[100], ch;
	int l=1, c=0;  
	printf("\nEnter the filename to open for reading: "); 
	scanf("%s", filename); 
	fptr1= fopen(filename, "r"); 

	if(fptr1==NULL)
	{
		printf("Cannot open file %s \n", filename); 
		exit(0); 
	}
	ch=getc(fptr1); 
	while(ch!=EOF)
	{
		if(ch=='\n')
		{
			l++; 
		}
		c++; 
		ch=getc(fptr1); 
	}
	printf("Number of Lines: %d\n", l); 
	printf("Number of characters: %d\n", c);
	fclose(fptr1); 
	return 0; 
}