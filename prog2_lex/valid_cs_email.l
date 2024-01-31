/*Write a LEX Program to check valid email address.*/



%{
    #include <stdio.h>
    int valid = 0;
    
%}

%%

[\n\t ] ;
U[12][0-9][0-9][0-9]{4}@rajagiri\.edu\.in   {valid =1;} 
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

