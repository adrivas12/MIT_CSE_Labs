/*To reverse the file contents and store in another file. Also display the size of file using file handling
function.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr1, *fptr2;
	char filename[1000], c, s[1000]; 
	printf("\nEnter the filename to open for reading: "); 
	scanf("%s", filename); 
	fptr1=fopen(filename, "r"); 

	if(fptr1==NULL)
	{
		printf("Cannot open file %s \n", filename); 
		exit(0); 
	}
	printf("Enter the filename to open for writing: "); \
	scanf("%s", filename); 
	fptr2=fopen(filename, "w+"); 

	//int fseek(FILE *fptr1, int 448, SEEK_SET);
	c=fgetc(fptr1); 
	int i=0; 
	while(c!=EOF)
	{
		s[i]=c; 
		i++;
		c=fgetc(fptr1);
	}

	int n=i; 
	for(i=n-1; i>=0; i--)
	{
		fputc(s[i], fptr2); 
	}
	printf("Reversed the contents and copied to %s", filename); 
	printf("\nSize of the file: %d\n", n); 
	fclose(fptr1); 
	fclose(fptr2); 
	return 0; 
}