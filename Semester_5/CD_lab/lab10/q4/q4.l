%{
	#include"q4.tab.h"
%}
%%

[0-9]+ {return NUM; }

\n {return NL;}


%%
int yywrap(){
	return 1;
}