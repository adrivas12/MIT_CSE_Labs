%{
#include "parser.tab.h"
%}

digit     [0-9]
letter    [a-zA-Z]
id        {letter}({letter}|{digit})*

%%

"public"   { return PUBLIC; }
"static"   { return STATIC; }
"void"     { return VOID; }
"class"    { return CLASS; }
"interface" { return INTERFACE; }
"main"     { return MAIN; }
"String"   { return STRING; }
"args"     { return ARGS; }
"if"       { return IF; }
"while"    { return WHILE;