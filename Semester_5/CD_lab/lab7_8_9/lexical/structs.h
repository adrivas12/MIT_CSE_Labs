#ifndef __STRUCTS_H__
#define __STRUCTS_H__

struct token
{
	char lexeme[64]; 
	int row, col; 
	int index; 
	char return_type[20]; 
	char data_type[20]; 
	char token_type[20]; 
	int argc; 
	char type[20]; 
}; 
struct ListElement
{
	struct token tkn; 
	struct ListElement *next; 
};

#endif