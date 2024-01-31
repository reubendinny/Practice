#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

int n;
char grammar[50][50];

/*
S->ABc|e
A->b|$
B->c|$

*/
int dollar_exist(char g[]){
    for(int i =0; g[i] != '\0' ; i++){
        if(g[i] == '$'){
            return 1;
        }
    }
    return 0;
}


int first(char g[],int p){
    char list[50];
    int dollar = 0;
    int k =0;
    list[k++] = g[p];

    if(dollar_exist(g)){
        dollar = 1;
    }

    for(int j = 0; g[j] != '\0';j++){
        if(g[j] == '|'){           
            list[k++] =  g[j+1];

        }
    }
    
    list[k] = '\0';

    // printf("The symbols are:");
    // for(int k = 0; list[k] != '\0';k++){
    //     printf("%c",list[k]);
    // }
    // printf("End");
    
    
    for(int k = 0; list[k] != '\0';k++){
        if(islower(list[k])){
            printf("%c ",list[k]);
            // return dollar;
        }



        else{
            for(int i=0;i<n;i++){

                if(grammar[i][0] == list[k]){
                    printf("\ncalling first of %c: ",grammar[i][0]);
                    while(first(grammar[i],3)){
                        if(!first(g,p+1)){
                            break;
                        }
                    }
                }

            }

        }
    }
    return dollar;

}



void main(){
    int i;
    int p = 3;

    printf("Enter the number of symbols");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s",grammar[i]);
    }

    for(i=0;i<n;i++){
        printf("First of %c: { ",grammar[i][0]);
        if(first(grammar[i],p)){
            printf("$");
        }

        printf("}\n");
    }

}