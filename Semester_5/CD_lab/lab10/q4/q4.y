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

%start Input
%%
Input:
     | Input Line
	;

Line:END
    | exp END { float answer = $1; int ans= answer; if((float) ans == answer){printf("%d\n",ans);} 
			else {printf("%f\n",answer);}
	;

exp:NUMBER { $$=$1; }
	| exp exp PLUS{ $$=$1+$3; }
	| exp exp MINUS{ $$=$1-$3; }
	| exp exp TIMES{ $$=$1*$3; }
	| exp exp DIVIDE{ $$=$1/$3; }
	| LEFT exp RIGHT { $$=$2; }
	;
%%

extern char* yytext;
int yyerror(char *msg){
	printf("Invalid decision making statement\n"); 
	exit(0); 
}
int main(){
	printf("Enter the decision statement: ");
	yyparse(); 
}