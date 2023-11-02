%{
	#include <stdio.h>
	#include <math.h>
	#define YYSTYPE double 
	#include <stdlib.h>	
%}

%token NUMBER
%token PLUS MINUS TIMES DIVIDE POWER
%token LEFT RIGHT
%token END

%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%right POWER

%start Input
%%

Input:
     | Input Line
	;

Line:END
    | exp END { printf("Result: %f\n", $1); }
	;

exp:NUMBER { $$=$1; }
	| exp PLUS exp { $$=$1+$3; }
	| exp MINUS exp { $$=$1-$3; }
	| exp TIMES exp { $$=$1*$3; }
	| exp DIVIDE exp { $$=$1/$3; }
	| MINUS exp %prec NEG { $$=-$2; }
	| LEFT exp RIGHT { $$=$2; }
	;

%%
int yyerror(char *msg){
	printf("Invalid decision making statement\n"); 
	exit(0); 
}
int main(){
	printf("Enter the decision statement: ");
	yyparse(); 
}