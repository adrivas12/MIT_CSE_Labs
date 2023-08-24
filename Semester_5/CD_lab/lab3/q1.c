/*Write functions to identify the following tokens.
a. Arithmetic, relational and logical operators.
b. Special symbols, keywords, numerical constants, string literals and identifiers.
Design a lexical analyzer which contains getNextToken( ) for a simple C program to create a
structure of token, which includes row number, column number and token type of the identified
tokens. The getNextToken() should ignore all the tokens when encountered inside single line or
multiline comment inside string literal. Preprocessor directives should also be stripped.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ARL(FILE *fptr)
{
	char c=fgetc(fptr); 
	char buf[100]; 
	while(c!=EOF)
	{
		int i=0; 
		buf[0]='\0';

		if(c == '=')
		{
			buf[i++]=c; 
			c=fgetc(fptr); 
			if(c == '=')
			{
				buf[i++]=c; 
				buf[i]='\0'; 
				printf("Relational operator: %s\n", buf); 
			}
			else
			{
				buf[i]='\0'; 
				printf("Assignment operator: %s\n", buf); 
			}
		}
		else if(c=='<'||c=='>'||c=='!')
		{
			buf[i++]=c; 
			c=fgetc(fptr); 
			if(c=='=')
			{
				buf[i++]=c; 
			}
			buf[i]='\0'; 
			printf("Relational operator: %s\n", buf); 
		}
		else if(c=='+') 								//Arithmetic operator-----
		{
			buf[i++]=c; 
			c=fgetc(fptr); 
			if(c=='+')
			{
				buf[i++]=c; 
				buf[i]='\0';
				printf("Arithmetic operator: %s\n", buf); 
			}
			else
			{
				buf[i]='\0';
				printf("Arithmetic operator: %s\n", buf); 
			}
		}
		else if(c=='-')
		{
			buf[i++]=c; 
			c=fgetc(fptr); 
			if(c=='-')
			{
				buf[i++]=c; 
				buf[i]='\0';
				printf("Arithmetic operator: %s\n", buf); 
			}
			else
			{
				buf[i]='\0';
				printf("Arithmetic operator: %s\n", buf); 
			}
		}
		else if(c=='*' || c=='/' || c=='%')
		{
			buf[i++]=c; 
			c=fgetc(fptr); 
			buf[i]='\0'; 
			printf("Arithmetic operator: %s\n", buf);  
		}												//Arithmetic operator end-----
		else if(c=='&')									//Logical operator -----------
		{
			buf[i++]=c; 
			c=fgetc(fptr); 
			if(c=='&')
			{
				buf[i++]=c; 
				buf[i]='\0'; 
				printf("Logical operator: %s\n", buf); 
			}
		}
		else if(c=='|')
		{
			buf[i++]=c; 
			c=fgetc(fptr); 
			printf("Logical operator: %s\n", buf); 
		}												//Logical operator end-----
		c=fgetc(fptr); 
	}
}

int main()
{
	char c, buf[10]; 
	FILE *fptr=fopen("digits.c", "r"); 
	c=fgetc(fptr); 
	if(fptr == NULL)
	{
		printf("Cannot open file\n"); 
		exit(0); 
	}

	ARL(fptr); 
}