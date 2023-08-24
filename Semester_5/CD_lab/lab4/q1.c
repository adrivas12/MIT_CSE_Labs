/*1. Using getNextToken( ) implemented in Lab No 3, design a Lexical Analyser to implement the
following symbol tables.
a. local symbol table
b. global symbol table*/

//incomplete (return type and no of arguments)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FILEINPUT "input.c"
#define max_size 20

int preProcessIgnore()
{
	FILE *fin = fopen(FILEINPUT, "r");
	char c = 0;
	char buffer[100];
	buffer[0] = '\0';
	int i = 0;
	char *includeStr = "include", *defineStr = "define", *mainStr = "main";
	int mainFlag = 0, rowNum = 1;
	while(c != EOF)
	{
		c = fgetc(fin);
		if(c == '#' && mainFlag == 0)
		{
			c = 'a';
			while(isalpha(c) != 0)
			{
				c = fgetc(fin);
				buffer[i++] = c;
			}
			buffer[i] = '\0';
			if(strstr(buffer, includeStr) != NULL || strstr(buffer, defineStr) != NULL)
			{
				rowNum++;
				while(c!='\n')
				{
					c = fgetc(fin);
				}
			}
			else
			{
				for(int j=0;j<i;j++);
				while(c!='\n'){
					c = fgetc(fin);
				}
			}
			i = 0;
			buffer[0]= '\0';
		}
		else
		{
			if(mainFlag == 0)
			{
				buffer[i++] = c;
				buffer[i] = '\0';
				if(strstr(buffer, mainStr) != NULL)
				{
					mainFlag = 1;
				}
			}
			if(c == ' ' || c == '\n')
			{
				buffer[0] = '\0';
				i = 0;
			}
		}
	}
	fclose(fin);
	return rowNum;
}
const char keywords[32][10] = {"auto", "double", "int", "struct",
"break", "else", "long", "switch", "case", "enum", "register",
"typedef", "char", "extern", "return", "union", "const", "float",
"short", "unsigned", "continue", "for", "signed", "void",
"default", "goto", "sizeof", "voltile", "do", "if", "static",
"while"}; // list of keywords
const char special_symbols[] = {'?', ';', ':', ',' }; //special symbols
const char operators[] = {'*','+','-','/'}; //arithmetic symbols 
const char brackets[]= {'(', ')', '[', ']', '{', '}'}; //brackets 
const char data_types[][10]={"double", "int", "char", "float"}; 
static int ind=0; 
//lexeme type enumerator
enum TYPE{
	IDENTIFIER,
	KEYWORD,
	STRING_LITERAL,
	NUMERIC_CONSTANT,
	OPERATOR,
	BRACKET,
	SPECIAL_SYMBOL,
	RELATIONAL_OPERATOR,
	CHARACTER_CONSTANT
};
//map for the type to string
char types[][30] = {"IDENTIFIER", "KEYWORD", "STRING_LITERAL",
"NUMERIC_CONSTANT", "OPERATOR", "BRACKET", "SPECIAL_SYMBOL",
"RELATIONAL_OPERATOR", "CHARACTER_CONSTANT"};

//create structure of token 
typedef struct token
{
    char *current;
    int row, col;
    struct token *next; 
    enum TYPE type;
} *Token;

//create structure of symbol table
typedef struct symbol
{
	int index; 
	char *lexname; 
	char *ret_type; 
	char *data_type;
	char *token_type; 
	struct symbol *next; 
	int argument_nos; 
} *Symbol; 

//hash and symbol table creation 
Token HT[max_size];  
Symbol ST[max_size];


int isKeyword(const char *str)
{
    for (int i = 0; i < sizeof(keywords)/sizeof(char *); i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
int isDatatype(char *str)
{
	for(int i=0; i<sizeof(data_types)/sizeof(char *); i++)
	{
		if(strcmp(str, data_types[i])==0)
			return 1; 
	}
	return 0; 
}
int isOperator(char ch)
{
	for(int i=0; i<sizeof(operators)/sizeof(char); i++)
	{
		if(operators[i]==ch)
			return 1; 
	}
	return 0; 
}
int isBracket(char ch)
{
	for(int i=0; i<sizeof(brackets)/sizeof(char); i++)
	{
		if(brackets[i]==ch)
			return 1; 
	}
	return 0; 
}
int isSpecialSymbol(char ch)
{
	for(int i=0; i<sizeof(special_symbols)/sizeof(char); i++)
	{
		if(special_symbols[i]==ch)
			return 1; 
	}
	return 0; 
}

int hash(int size)
{
	return (size%max_size); 
}

//display Symbol Table
void displayST()
{
	printf("\nSymbol Table \nIndex, lexname, Return type, Data type, Token type, no. of arguments)\n\n");
	for(int i=0; i<max_size; i++)
	{
		if(ST[i]==NULL)
			continue; 
		else
		{
			Symbol cur=ST[i]; 
			while(cur)
			{
				printf("%d  %8s  %8s  %8s  %8s  %d\n", cur->index, cur->lexname, cur->ret_type, cur->data_type, cur->token_type, cur->argument_nos); 
				cur=cur->next; 
			}
		}
	}
}
//Search Through the Symbol Table 
int searchST(char id[], char data_type[])
{
	int index=hash(strlen(id)); 
	if(ST[index]==NULL)
		return -1; 

	Symbol cur=ST[index]; 
	int i=0; 
	while(cur!=NULL)
	{
		if(strcmp(id, cur->lexname)==0)
			return i; 
		cur=cur->next; 
		i++; 
	}
	return -1; 
}
//Search Through the Hash Table
int searchHT(char buf[], enum TYPE type)
{
	int ind=hash(strlen(buf));
	if(HT[ind]==NULL)
		return 0; 
	Token cur=HT[ind]; 
	while(cur!=NULL)
	{
		if(strcmp(cur->current, buf)==0)
			return 0; 
		cur=cur->next; 
	}
	return 0; 
}

//Insert in the Symbol Table 
void insertST(char id[], char data_type[])
{
	if(searchST(id, data_type)==-1)
	{
		Symbol n=(Symbol)malloc(sizeof(struct symbol)); 
		char *str=(char *)calloc(strlen(id)+1, sizeof(char)); 
		strcpy(str, id); 
		n->index=ind; 
		ind++; 
		n->lexname=str; 
		n->next=NULL; 
		char *dataTypee=(char *)calloc(strlen(data_type)+1, sizeof(char)); 
		strcpy(dataTypee, data_type);
		n->data_type=dataTypee; 

		if(strcmp(data_type, "int")==0 || strcmp(data_type, "double")==0 || strcmp(data_type, "char")==0 || strcmp(data_type, "float")==0 )
			n->token_type="var"; 
		else if(strcmp(data_type, "function")==0)
			n->token_type="function"; 

		/*if(strcmp(data_type, "function")==0)
		{
			while()
		}*/
		int index=hash(strlen(id)); 
		if(ST[index]==NULL)
		{
			ST[index]=n; 
			return; 
		}
		Symbol cur=ST[index]; 
		while(cur->next!=NULL)
			cur=cur->next; 
		cur->next=n; 
	}
}

//insert in Hash Table 
void insertHT(char buf[], int row, int col, enum TYPE type)
{
	if(type==IDENTIFIER || searchHT(buf, type)==0)
	{
		printf("< %s, %d, %d, %s>\n", buf, row, col, types[type]); 
		int index=hash(strlen(buf)); 
		Token n=(Token)malloc(sizeof(struct token)); 
		char *str=(char *)calloc(strlen(buf)+1, sizeof(char)); 
		strcpy(str, buf); 
		n->current=str; 
		n->next=NULL; 
		n->row=row; 
		n->col=col; 
		n->type=type; 
		if(HT[index]==NULL)
		{
			HT[index]=n; 
			return; 
		}
		Token cur=HT[index]; 
		while(cur->next!=NULL)
			cur=cur->next; 
		cur->next=n; 
	}
}

int main()
{
	int rowNum=preProcessIgnore(); 
	enum TYPE type; 
	for(int i=0; i<max_size; i++)
		HT[i]=NULL; 
	FILE *fin=fopen(FILEINPUT, "r"); 
	if(fin==NULL)
	{
		printf("Cannot open file\n"); 
		return 0; 
	}

	char buf[100], c=0, data_type_buf[100]; 
	int i=0, col_global=1, col, temp_row=--rowNum; 
	while(temp_row>0)
	{
		c=fgetc(fin); 
		if(c=='\n')
			temp_row--; 
	}

	while(c!=EOF)
	{
		if(isalpha(c)!=0 || c=='_')
		{
			buf[i++]=c; 
			col=col_global; 
			while(isalpha(c)!=0 || c=='_' || isdigit(c)!=0)
			{
				c=fgetc(fin); 
				col_global++; 
				if(isalpha(c)!=0 || c=='_' || isdigit(c)!=0)
					buf[i++]=c; 
			}
			buf[i]='\0'; 
			if(isDatatype(buf)==1)
			{
				insertHT(buf, rowNum, col-1, KEYWORD); 
				strcpy(data_type_buf, buf); 
			}
			else if(isKeyword(buf)==1)
			{
				insertHT(buf, rowNum, col-1, KEYWORD); 
			}
			else
			{
				insertHT(buf, rowNum, col-1, IDENTIFIER); 
				if(c=='(')
					insertST(buf, "function"); 
				else 
					insertST(buf, data_type_buf); 
				data_type_buf[0]='\0'; 
			}
			i=0; 
			if(c=='\n')
				rowNum++, col_global=1; 
			buf[0]='\0'; 
		}
		else if(isdigit(c) !=0)
		{
			buf[i++]=c; 
			col=col_global; 
			while(isdigit(c)!=0||c=='.')
			{
				c=fgetc(fin); 
				col_global++; 
				if(isdigit(c)!=0 || c=='.')
					buf[i++]=c; 
			}
			buf[i]='\0'; 
			insertHT(buf, rowNum, col-1, NUMERIC_CONSTANT); 
			i=0; 
			if(c=='\n')
				rowNum++, col_global=1; 
			buf[0]='\0'; 
		}
		else if(c=='\"')
		{
			col = col_global;
			buf[i++] = c;
			c = 0;
			while(c != '\"'){
				c = fgetc(fin);
				col_global++;
				buf[i++] = c;
			}
			buf[i] = '\0';
			insertHT(buf, rowNum, col-1, STRING_LITERAL); // string literals
			buf[0] = '\0';
			i = 0;
			c = fgetc(fin);
			col_global++;
		}
		else if(c=='\'')
		{
			col = col_global;
			buf[i++] = c;
			c = 0;
			c = fgetc(fin);
			col_global++;
			buf[i++] = c;
			if(c == '\\'){
				c = fgetc(fin);
				col_global++;
				buf[i++] = c;
			}
			c = fgetc(fin);
			col_global++;
			buf[i++] = c;
			buf[i] = '\0';
			insertHT(buf, rowNum, col-1, CHARACTER_CONSTANT); //character constants
			buf[0] = '\0';
			i=0;
			c = fgetc(fin);
			col_global++;
		}
		else
		{
			col = col_global;
			if(c == '=')
			{ // relational and logical operators
				c = fgetc(fin);
				col_global++;
				if(c == '='){
					insertHT("==", rowNum, col-1, RELATIONAL_OPERATOR);
				}
				else{
					insertHT("=", rowNum, col-1, RELATIONAL_OPERATOR);
					fseek(fin, -1, SEEK_CUR);
					col_global--;
				}
			}
			else if(c == '>' || c == '<' || c == '!')
			{
				char temp = c;
				c = fgetc(fin);
				col_global++;
				if(c == '=')
				{
					char temp_str[3] = {temp, '=', '\0'};
					insertHT(temp_str, rowNum, col-1, RELATIONAL_OPERATOR);
				}
				else
				{
					char temp_str[2] = {temp, '\0'};
					insertHT(temp_str, rowNum, col-1, RELATIONAL_OPERATOR);
					fseek(fin, -1, SEEK_CUR);
					col_global--;
				}
			}
			else if(isBracket(c) == 1)
			{
				char temp_string[2] = {c,'\0'};
				insertHT(temp_string, rowNum, col-1, BRACKET);
			}
			else if(isSpecialSymbol(c) == 1)
			{
				char temp_string[2] = {c,'\0'};
				insertHT(temp_string, rowNum, col-1, SPECIAL_SYMBOL);
			}
			else if(isOperator(c) == 1)
			{
				char temp = c;
				c = fgetc(fin);
				col_global++;
				if (c == '=' || (temp == '+' && c == '+') || (temp == '-' && c == '-'))
				{
					char temp_string[3] = {temp,c,'\0'};
					insertHT(temp_string, rowNum, col-1, OPERATOR);
				}
				else
				{
					char temp_String[2] = {temp,'\0'};
					insertHT(temp_String, rowNum, col-1, OPERATOR);
					fseek(fin, -1, SEEK_CUR);
					col_global--;
				}
			}
			else if(c == '\n') 
				rowNum++, col_global = 1;
			c = fgetc(fin);
			col_global++;
		}
	}
	displayST(); 
	return 0; 
}