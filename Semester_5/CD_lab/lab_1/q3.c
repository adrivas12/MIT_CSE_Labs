//That merfes lines alternatively from 2 files and stores it in a resultant file,

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr1, *fptr2, *fptr3; 
	char filename[100], c1, c2;  
	fptr1=fopen("samp.txt", "r"); 
	fptr2=fopen("samp1.txt", "r"); 
	fptr3=fopen("samp3.txt", "w+"); 

	while(c1!=EOF && c2!=EOF)
	{
		
		if(c1!=EOF)
		{
			c1=fgetc(fptr1); 
			while(c1!='\n')
			{
				if(c1==EOF)
					break; 
				fputc(c1, fptr3); 
				c1=fgetc(fptr1); 
			}
			if(c1!=EOF)
				fputc('\n', fptr3); 
		}
		if(c2!=EOF)
		{
			c2=fgetc(fptr2); 
			while(c2!='\n')
			{
				if(c2==EOF)
					break; 
				fputc(c2, fptr3); 
				c2=fgetc(fptr2); 
			}
			if(c2!=EOF)
				fputc('\n', fptr3); 
		} 
		
	}
	printf("Files merged into a new file\n");
	fclose(fptr1); 
	fclose(fptr2); 
	fclose(fptr3); 
	return 0; 
}


