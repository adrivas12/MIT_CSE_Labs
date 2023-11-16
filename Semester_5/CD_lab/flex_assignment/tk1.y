%token PUBLIC STATIC VOID MAIN STRING ID NUM
%token LPAR RPAR LBRACE RBRACE SEMICOLON
%token IF WHILE FOR ELSE RETURN
%token LESS GREATER LESSEQUAL GREATEREQUAL EQUAL NOTEQUAL ASSIGN

%start Main
%token <char*> STRING_LITERAL

%%

Main: PUBLIC STATIC VOID MAIN LPAR STRING LBRACE RBRACE LBRACE CommandList RBRACE '¥'
    ;

CommandList: Command CommandList
    | /* empty */
    ;

Command: Condition
    | Loop
    | Assignment
    | Return
    ;

Condition: IF LPAR Comparison RPAR LBRACE CommandList RBRACE
    ;

Loop: WHILE LPAR Comparison RPAR LBRACE CommandList RBRACE
    | FOR LPAR ForInit SEMICOLON ForCondition SEMICOLON ForInit RPAR LBRACE CommandList RBRACE
    ;

ForInit: Assignment
    | /* empty */
    ;

ForCondition: Comparison
    | /* empty */
    ;

Comparison: Var Relop Var
    ;

Relop: LESS
    | GREATER
    | LESSEQUAL
    | GREATEREQUAL
    | EQUAL
    | NOTEQUAL
    ;

Assignment: Name ASSIGN Type SEMICOLON
    ;

Return: RETURN RetVal SEMICOLON
    ;

RetVal: Name
    | Type
    ;

Name: ID
    ;

Var: ID
    | NUM
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

%%