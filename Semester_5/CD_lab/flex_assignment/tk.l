%{
#include "tk.tab.h"  // Bison-generated header file
%}

digit [0-9]
id [a-zA-Z_][a-zA-Z0-9_]*

%%
"public"    { return PUBLIC; }
"private"   { return PRIVATE; }
"protected" { return PROTECTED; }
"class"     { return CLASS; }
"interface" { return INTERFACE; }
"implements" { return IMPLEMENTS; }
"extends"   { return EXTENDS; }
"static"    { return STATIC; }
"string"    { return STRING; }
"int"       { return INT; }
"boolean"   { return BOOLEAN; }
"void"      { return VOID; }
"if"        { return IF; }
"while"     { return WHILE; }
"for"       { return FOR; }
"return"    { return RETURN; }
"true"|"false" { return BOOLEAN_LITERAL; }
">=" { return GTEQ; }  // GTEQ is a token for '>='
"<=" { return LTEQ; }  // LTEQ is a token for '<='
"==" { return EQEQ; }  // EQEQ is a token for '=='
"!=" { return NOTEQ; } // NOTEQ is a token for '!='

{digit}+    { return INT_LITERAL; }
{id}        { return IDENTIFIER; }
[ \t\n]     ;  // Skip whitespaces
.           { return yytext[0]; }  // Return single characters as-is
%%

int yywrap()
{
return 1;
}