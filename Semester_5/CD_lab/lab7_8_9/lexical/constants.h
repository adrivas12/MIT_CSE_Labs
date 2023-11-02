#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

char keywords[34][10]=
{
	"true", 
	"false",
	"auto",
	"double",
	"int",
	"struct",
	"break",
	"else",
	"long",
	"switch",
	"case",
	"enum",
	"register",
	"typedef",
	"char",
	"extern",
	"return",
	"union",
	"const",
	"float",
	"short",
	"unsigned",
	"continue",
	"for",
	"signed",
	"void",
	"default",
	"goto",
	"sizeof",
	"voltile",
	"do",
	"if",
	"static",
	"while"			  // list of keywords
};
char data_types[][10]=
{
	"double", 
	"int", 
	"char", 
	"float"
};					//list of data types
char return_types[][10]=
{
	"int", "float", "char", "void","double","long"
};
char operators[5]=
{
	'+', '-', '/', '*', '%'
};
char brackets[6]=
{
	'(', ')', '{', '}', '[', ']'
}; 
char special_symbols[12]=
{
	'*', ';', ':', '.', ',', '^', '&', '!', '>', '<', '~'
}; 
enum TYPE
{
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
char types[][30]=
{
	"IDENTIFIER",
	"KEYWORD",
	"STRING_LITERAL",
	"NUMERIC_CONSTANT",
	"OPERATOR",
	"BRACKET",
	"SPECIAL_SYMBOL",
	"RELATIONAL_OPERATOR",
	"CHARACTER_CONSTANT"
};
char *predefFuncs[]={"printf", "scanf"}; 
int row=1, col=1; 

#endif
