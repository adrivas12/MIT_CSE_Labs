//To discard preprocessor directives from the given input 'C' file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

const char *direct[]={"#include", "#define", "#if"}; 

int isDirective(const char *str)
{
	for(int i=0; i<sizeof(direct)/sizeof(char *); i++)
	{
		int len=strlen(direct[i]); 
		if(strncmp(str, direct[i], len)==0)
		{
			return 1; 
		}
	}
	return 0;
}

int main()
{
	FILE *fptr1, *fptr2; 
	char buf[2048];
	fptr1= fopen("q1.c", "r"); 
	if(fptr1==NULL)
	{
		printf("Cannot open file\n"); 
		exit(0); 
	}

	fptr2=fopen("q1out.c", "w"); 
	while(fgets(buf, 2048,fptr1)!=NULL)
	{ 
		if(isDirective(buf)==0)
		{
			fputs(buf, fptr2); 
		}
	}
	fclose(fptr1); 
	fclose(fptr2); 
	return 0;
}