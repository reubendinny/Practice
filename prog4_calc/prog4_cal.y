%{
    #include <stdio.h>
    int valid = 1;    
%}


%token num
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

start: E    {printf("result: %d\n",$$);} ;
E:  E '+' E  {$$=$1+$3;  printf("%d %d %d",$1,$2,$3); }    | 
    E '-' E  {$$=$1-$3; printf("%d %d %d",$1,$2,$3);}    |
    E '*' E  {$$=$1*$3;}    |
    E '/' E  {$$=$1/$3;}    |

    num {$$ = $1;};         





%%


int yyerror(){
    valid = 0;
    printf("ERROT");
    return 0;
}


int main(){
    printf("Enter the expression:");
    yyparse();
    if(valid){
        printf("valid");
    }

}