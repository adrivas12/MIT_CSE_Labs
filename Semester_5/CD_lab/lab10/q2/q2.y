%{
	#include <stdio.h>
	#include <stdlib.h>	
%}

%token IF ELSE SWITCH OB CB ID GT LT EQ NL NUM

%%

stmt: DC NL
	; 
DC: DT  OB IDL CB{printf("Valid decision making statement\n"); exit(0); }
DT: IF
	|ELSE
	|SWITCH
	; 
IDL: ID 
	|NUM
	|NUM GT NUM
	|NUM LT NUM
	|NUM EQ NUM
	|ID GT ID
	|ID LT ID
	|ID EQ ID
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