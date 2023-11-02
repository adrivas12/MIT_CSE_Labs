%{
	#include <stdio.h>
	int number = 0; 
%}
%%
number[0-9]+ {printf("numberjssjsj%x",number); }
%%
number {printf("numberjssjsj%x",number); }
int yywrap(){return 1; }
int main()
{
	printf("Enter a numbers: \n"); 
	yylex();  
}
