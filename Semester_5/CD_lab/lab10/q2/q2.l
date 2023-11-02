%{
	#include"q2.tab.h"
%}
%%

"if" {return IF;}
"else" {return ELSE;}
"switch" {return SWITCH;}
"(" {return OB;}
[0-9]+ {return NUM;}
[a-zA-Z][a-zA-Z0-9_]* {return ID;}
">" {return GT; }
"<" {return LT; }
"==" {return EQ; }
")" {return CB;}
\n {return NL;}

%%
int yywrap(){
	return 1;
}