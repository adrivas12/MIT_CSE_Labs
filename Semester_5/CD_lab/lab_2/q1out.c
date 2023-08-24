//That takes a file as input and replaces blank spaces and tabs by single space and writes the output to a file 


int main()
{
	FILE *fptr1, *fptr2; 
	int ch1, flag; 
	fptr1= fopen("in.txt", "r"); 
	if(fptr1==NULL)
	{
		printf(" Cannot open file\n"); 
		exit(0); 
	}

	fptr2=fopen("out.txt", "w"); 
	while(ch1!=EOF)
	{ 
		ch1=getc(fptr1);
		if(!flag && (ch1==' ' || ch1=='\t'))
		{
			putc(' ', fptr2); 
			flag=1; 
		}
		else if(!(ch1==' '|| ch1=='\t'))
		{
			flag=0; 
			fputc(ch1, fptr2); 
		}
	
	}
	fclose(fptr1); 
	fclose(fptr2); 
	return 0;
}

