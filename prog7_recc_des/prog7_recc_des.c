#include <stdio.h>
#include <stdlib.h>

char str[100];
int i = 0;



void A(){
    if(str[i] == 'a'){
        i++;
    }
    else{
        printf("ERROR");
        exit(0);

    }
    if(str[i] == 'b' || str[i] == 'c' ){
        i++;
    }
    else{
        printf("ERROR");
        exit(0);

    }
}

void S(){
    if(str[i] == 'c'){
        i++;
    }
    else{
        printf("ERROR");
        exit(0);

    }

    A();

    if(str[i] == 'd'){
        i++;
    }
    else{
        printf("ERROR");
        exit(0);

    }

   
}

void main(){
    printf("Enter the string:");
    scanf("%s",str);

    S();

    printf("valid");

}

