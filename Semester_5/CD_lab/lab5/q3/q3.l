%{
	#include <stdio.h>
	int pos_int = 0; 
	int neg_int = 0; 
	int pos_float = 0; 
	int neg_float = 0; 
%}
%%
\+?[0-9]+ {pos_int++; }
-[0-9]+ {neg_int++; }
\+?[0-9]+\.[0-9]+ { pos_float++; }
-[0-9]+\.[0-9]+ {neg_float++;}
%%
int yywrap(){return 1;}
int main()
{
	printf("Enter the numbers: \n"); 
	yylex(); 
	printf("Positive Integers: %d\n", pos_int); 
	printf("Negative Integers: %d\n", neg_int); 
	printf("Positive Float: %d\n", pos_float); 
	printf("Negative Float: %d\n", neg_float); 
}