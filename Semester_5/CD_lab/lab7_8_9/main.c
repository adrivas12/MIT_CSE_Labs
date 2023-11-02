/* Program->main() {declarations assign_stat}
declarations->data-type identifier-list; declarations|e
data-type->int|char
identifier-list->id|id, identifier-list
assign_stat->id=id;|id=num; */


#define false 0
#define true 1
#include "lexical/lexeme.h"

struct token cur; 
FILE *f; 

void declarations(); 
void dataTypes(); 
void identifierList(); 
void assignStat(); 

void valid()
{
	printf("SUCCESS"); 
	exit(EXIT_SUCCESS); 
}
void invalid()
{
	printf("ERROR"); 
	exit(EXIT_FAILURE); 
}
void declarations()
{
	dataTypes(); 
	identifierList(); 
	if(strcmp(cur.lexeme, ";")==0)
	{
		cur=getNextToken(f); 
		if(isDataType(cur.lexeme)==0)
			return; 
		declarations(); 
	}
	else
	{
		printf("Missing \";\" at Row: %d and Column: %d\n", cur.row, cur.col); 
		exit(EXIT_FAILURE); 
	}
}
void dataTypes()
{
	if(isDataType(cur.lexeme))
	{
		cur=getNextToken(f); 
		return; 
	}
	else 
	{
		printf("Missing Data Type at Row: %d and Column: %d\n", cur.row, cur.col); 
		exit(EXIT_FAILURE); 
	}
}
void identifierList()
{
	if(stcmp(cur.type, "Identifier")==0)
	{
		cur=getNextToken(f); 
		if(strcmp(cur.lexeme, ",")==0)
		{
			cur=getNextToken(f); 
			identifierList(); 
		}
		else if(strcmp(cur.type, "Identifier")==0)
		{
			printf("Missing \",\" at Row: %d and Column: %d\n", cur.row, cur.col); 
			exit(EXIT_FAILURE); 
		}
		else 
		return; 
	}
	else
	{
		printf("Missing Identifier at Row: %d and Column: %d\n", cur.row, cur.col); 
		exit(EXIT_FAILURE); 
	}
}
void assignStat()
{
	if(strcmp(cur.type, "Identifier")==0)
	{
		cur=getNextToken(f); 
		if(strcmp(cur.lexeme, "=")==0)
		{
			cur=getNextToken(f); 
			if(strcmp(cur.type, "Identifier")==0)
			{
				cur=getNextToken(f); 
				if(strcmp(cur.lexeme, ";")==0)
				{
					cur=getNextToken(f); 
					return; 
				}
				else 
				{
					printf("Missing \";\" at Row: %d and Column: %d\n", cur.row, cur.col); 
					exit(EXIT_FAILURE); 
				}
			}
			else if(strcmp(cur.type, "Number")==0)
			{
				cur=getNextToken(f); 
				if(strcmp(cur.lexeme, ";")==0)
				{
					cur=getNextToken(f); 
					return; 
				}
				else 
				{
					
				}
			}
		}
	}
}