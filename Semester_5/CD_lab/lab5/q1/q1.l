%{
    #include <stdio.h>
    int vowels = 0;
    int consonants = 0;
%}
%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants++;}
%%
int main() {
    printf("Enter a string: \n");
    yylex();
    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
}
int yywrap() {return 1;}



