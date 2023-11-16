%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern char* yytext;
// extern int yylval;

void yyerror(const char *msg);

%}

%union {
    int intValue;
    char* strValue;
}

%token PUBLIC PRIVATE PROTECTED CLASS INTERFACE IMPLEMENTS EXTENDS STATIC STRING INT BOOLEAN VOID
%token IF WHILE FOR RETURN BOOLEAN_LITERAL INT_LITERAL IDENTIFIER
%token GTEQ LTEQ EQEQ NOTEQ  // Add tokens for the multi-character operators

// %type <strValue> Name RetVal
// %type <intValue> Comparison Relop Var

%%

Program: Code { printf("Parsing successful!\n"); }
;

Code: ClassCode
| ClassCode Code
;

ClassCode: Modifier ClassType Name Extra '{' FunctionList '}'
;

Modifier: PUBLIC
| PRIVATE
| PROTECTED
| /* empty */
;

ClassType: CLASS
| INTERFACE
;

Extra: IMPLEMENTS Name
| EXTENDS Name
| /* empty */
;

FunctionList: Function FunctionList
| /* empty */
;

Function: Modifier IsStatic Type Name '(' ArgumentList ')' '{' CommandList '}'
;

IsStatic: STATIC
| /* empty */
;

Type: STRING
| INT
| BOOLEAN
| VOID
;

ArgumentList: Type Argument ArgumentList
| /* empty */
;

Argument: Name Separator
;

Separator: ','
| /* empty */
;

CommandList: Command CommandList
| /* empty */
;

Command: Condition
| Loop
| Assignment
| Return
;

Condition: IF '(' Comparison ')' '{' CommandList '}'
;

Loop: WHILE '(' Comparison ')' '{' CommandList '}'
| FOR '(' ForInit ';' ForCondition ';' ForInit ')' '{' CommandList '}'
;

ForInit: Assignment
| /* empty */
;

ForCondition: Comparison
| /* empty */
;

Comparison: Var Relop Var
;

Relop: '<'
| '>'
| GTEQ  // Use the token for '>='
| LTEQ  // Use the token for '<='
| EQEQ  // Use the token for '=='
| NOTEQ // Use the token for '!='
;

Assignment: Name '=' Type ';'
;

Return: RETURN RetVal ';'
;

RetVal: Name
| Type
;

Name: IDENTIFIER
;

Var: IDENTIFIER
| INT_LITERAL
| BOOLEAN_LITERAL
;

%%
void yyerror(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

int main() {
    yyparse();
    return 0;
}