%{
    #include <stdio.h>    
    int valid = 0;
    int num ;
%}


%%

[\t ]+ {;}
[0-9]!+ {valid = 1; num = atoi(yytext);}
. ;

%%


int yywrap(void){}


int main(){
    yylex();

    

    if(valid){
        int fact = 1;
        for(int i=1;i<=num;i++){
            fact = fact * i;
        }

        printf("fact:%d", fact);
    }
    else{
        printf("Error");
    }
}