%{
    #include <stdio.h>    
    int flag = 1;
%}


%token id


%%

    start: id '=' id ;

%%

int yyerror(){
    
    printf("Error");
    flag = 0;
    return 0;
}


int main(){
    yyparse();
    if(flag){
        printf("valid\n");

    }
}