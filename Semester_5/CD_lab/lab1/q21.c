/*To reverse the file contents and store in another file. Also display the size of file using file handling
function.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr1, *fptr2;
	char filename[1000], c, s[1000]; 
	printf("Enter the filename to open for reading: \n"); 
	scanf("%s", filename); 
	fptr1=fopen(filename, "r"); 

	if(fptr1==NULL)
	{
		printf("Cannot open file %s \n", filename); 
		exit(0); 
	}
	printf("Enter the filename to open for writing: \n"); \
	scanf("%s", filename); 
	fptr2=fopen(filename, "w+"); 

	fseek(fptr1, 0, SEEK_END);
	c=fgetc(fptr1); 
	int i=0; 
	while(c!=EOF)
	{
		i++; 
		putc(c, fptr2); 
		c=fgetc(fptr1);
	}

	printf("Reversed the contents and copied to %s\n", filename); 
	printf("Size of the file %d", i); 
	fclose(fptr1); 
	fclose(fptr2); 
	return 0; 
}