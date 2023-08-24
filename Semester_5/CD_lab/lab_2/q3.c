//That takes C program as input, recognizes all the keywords and prints them in upper case.

#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
  
const char *keywords[] = {"const", "char", "int","return", "for", "while", "do", "switch",
                            "if", "else","case", "break"};
 
int is_keyword(const char *str)
{
    for(int i = 0; i < sizeof(keywords)/sizeof(char *); ++i)
    {
        if(strcmp(str, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
void strtoupper(char *str, const int len)
{
    for(int i = 0; i < len; ++i)
    {
        str[i] = toupper(str[i]);
    }
}
 
enum{INSIDE_WORD,OUTSIDE_WORD};
 
int main()
{
    FILE *f1,*f2;
    int line=1,col=1,k=0;
    char c,buf[512];
    f1 = fopen("q1.c", "r");
	if(f1 == NULL)
	{
		perror("The input file doesn't exist\n");
	    return 1;
	}
 
	int state = OUTSIDE_WORD;
    printf("Keywords : \n");
 
    while((c = fgetc(f1)) != EOF)
    {
        switch(state)
        {
            case INSIDE_WORD:
       		if(isalpha(c))
            {
               buf[k++]=c;
            }
       		else
            {
                buf[k]='\0';
           		if(is_keyword(buf))
                {
                    strtoupper(buf, k);
                    printf("%s \n", buf);
                }
           		k=0;
                state=OUTSIDE_WORD;
            }
        	break;
        	case OUTSIDE_WORD:
        	if(isalpha(c))
            {
                buf[k++]=c;
                state=INSIDE_WORD;
            }
        break;
        }
    }
  fclose(f1);
}
