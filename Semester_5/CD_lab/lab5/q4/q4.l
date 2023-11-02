%{
	#include <stdio.h>
	int s_num = 0; 
	int p_num = 0; 
%}
%%
"scanf" {s_num++; fprintf(yyout, "readf");}
"printf" {p_num++; fprintf(yyout, "writef");}
%%
int yywrap() {return 1; }
int main()
{
	yyin = fopen("open.c", "r"); 
	yyout = fopen("out.c", "w"); 
	yylex(); 
	printf("Number of scanfs = %d\n", s_num); 
	printf("Number of printfs = %d\n", p_num); 
}