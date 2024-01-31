/*Write a LEX Program to check valid email address.*/



%{
    #include <stdio.h>
    int valid = 0;
    
%}

%%

[\n\t ] ;
[a-zA-Z0-9_]@rajagiri\.edu\.in   {valid =1;} 
. ;

%%

int yywrap(void){}


int main(){
    printf("Enter the email:\n");
    yylex();

    if(valid == 1){
        printf("Correct\n");
    }
    else{
        printf("wrong\n");
    }

    return 1;
}

