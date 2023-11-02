%{
	#include <stdio.h>
	#include <string.h>
	int words = 0; 
	int characters = 0; 
	int blanks = 0; 
	int lines = 0; 
%}
%%
[a-zA-Z]+ { words++; characters += strlen(yytext); }
[\n] { characters++; lines++; }
[ ]* { blanks++; }

. { characters++; }
%%
int yywrap(){
return 1;
}
int main()
{
    char str[20];
    printf("Enter input string: \n");
    yylex();
    printf("Lines: %d\n", lines); 
    printf("Words: %d\n", words); 
    printf("Characters: %d\n", characters); 
    printf("Blanks: %d\n", blanks); 
}

 