/*Write a lex program to display the number of lines, words and characters in an input text.
*/

%{
    #include <stdio.h>    
    int nw =0 , nl =0,nc =0;
    
%}

%%

[\t ] ;
([a-zA-Z0-9]+) {nw++; nc = nc + yyleng;}
\n {nl++;}
 . ;

%%

int yywrap(void){
    return 1;
}

int main(){
    printf("Enter the\n");
    yylex();

    printf("no. of chars = %d, no. of words = %d , no. of lines = %d",nc, nw,nl);
}