#include <stdio.h>
#include  <string.h>

int n;
char NT[20];
char rules[26][50];
char stack[30];
char input[20];
int top;

int charToIndex(char c){
    if(c > 'a'){
        return c - 'a';
    }
    return c - 'A';
}


int reduce(){

    for(int i =0;i<n;i++){

        char rule[20];
        strcpy(rule , rules[charToIndex(NT[i])]);

        char * token = strtok(rule, "|");

        while (token!=NULL)
        {
            stack[top+1] = '\0';
            if(strcmp(token , stack + strlen(stack) - strlen(token)) == 0){
                top = strlen(stack) - strlen(token);
                stack[top] = NT[i];
                printf("reduce %c->%s",NT[i],token);
                return top;
            }

            token = strtok(NULL , "|");
        }
        

    }
    return -1;


}


void main(){
    printf("Enter the number of rules: ");
    scanf("%d",&n);

    printf("Enter the rules: ");
    for(int i=0;i<n;i++){
        char str[20];
        scanf("%s",str);

        NT[i] = str[0];
        strcpy(rules[charToIndex(NT[i])] , str + 3);

        // printf("%d : %s\n",charToIndex(NT[i]),rules[charToIndex(NT[i])]);
    }

    printf("Enter the input string: ");
    scanf("%s",input);

    top = -1;
    stack[++top] = '$';

    int i = 0;
    printf("Stack\tInput\tAction\n");
    while(i<strlen(input)){
        
        stack[top+1] = '\0';
        printf("%s\t%s\t",stack,input + i);


     

        int check = reduce();

        if(check == -1){
            stack[++top] = input[i++];
            printf("shift");

        }


    

        printf("\n");
    }


}