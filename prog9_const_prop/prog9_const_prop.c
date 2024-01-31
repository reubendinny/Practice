#include <stdio.h>
#include <string.h>
#include <ctype.h>

char statements[20][100];
int n;
int values[26];

int charToIndex(char c)
{
    if (c >= 'a')
    {
        return c - 'a';
    }
    return c - 'A';
}

void main()
{

    printf("Enter the numebr of statements:");
    scanf("%d", &n);

    printf("Enter the statements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", statements[i]);
    }

    for (int i = 0; i < n; i++){
        printf("%s: ", statements[i]);

        const char delim[] = "+-/*=";

        char statement[100];

        int total = 0;
        
        
        strcpy(statement, statements[i]);

        char *token = strtok(statement, delim);
        char lhs = token[0];
        
        while (1){

            token = strtok(NULL, delim);
            if (token == NULL)
            {
                break;
            }

            int val;
            if(isdigit(token[0])){
                val = atoi(token);
            }
            else{
                val = values[charToIndex(token[0])];
            }


            printf("%s ", token);
            char op = statements[i][token - statement - 1];
            printf("%c " , op);

            switch (op)
            {
                case '+':{
                    total = total + val;
                    break;
                }
                case '-':{
                    total = total - val;
                    break;
                }
                case '*':{
                    total = total * val;
                    break;
                }
                case '/':{
                    total = total / val;
                    break;
                }
                case '=':{
                    total =  val;
                    break;
                }
                
            
                

            }


            
        }
        values[charToIndex(lhs)] = total;
        printf("total: %d\n",total);
    }
}