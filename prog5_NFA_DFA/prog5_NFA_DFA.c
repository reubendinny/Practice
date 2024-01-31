#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int f =0 , fs =0;
int front = - 1;
char queue[10][10];
char final[10][10];


int n_states,n_transitions,n_alphas;

struct state{
    char q[10];
    char transition[20][20];
                      

}initial_states[20],final_states[20];



int final_exist(char str[]){
    for(int i=0;i<10;i++){
        if(strcmp(str,final[i])==0){
            return 1;
        }
    }
    return 0;
}





void main(){
    printf("Enter the number of states:");
    scanf("%d",&n_states);



    printf("Enter the states:");
    for(int i = 0;i<n_states;i++){
        scanf("%d",&initial_states[i].q[0]);        
    }

   // scanf("%d",&n_states);

    printf("Enter the number of alphas:");
    scanf("%d",&n_alphas);

    printf("Enter the number of transitions:");
    scanf("%d",&n_transitions);

    printf("Enter the transitions:\n");
    printf("[enter it like 0-0-1]\n");


    for(int i=0;i<n_transitions;i++){
        
        char str[10];
        scanf("%s",str);

        char *token1 = strtok(str,"-");
        char *token2 = strtok(NULL,"-");
        char *token3 = strtok(NULL,"-");

        /*
            initial states: 0
            q 0
            transtion 0  01

            0 - 0 - 0
            0 - 0 - 1
        */


        strcpy(initial_states[atoi(token1)].q , token1);

        if(strlen(initial_states[atoi(token1)].transition[atoi(token2)]) >= 1){
            strcat(initial_states[atoi(token1)].transition[atoi(token2)] , token3);

        }
        else{
            strcpy(initial_states[atoi(token1)].transition[atoi(token2)] , token3);

        }

    }
    

    printf("state\t|0\t|1\t|\n");
    for(int i = 0;i<n_states;i++){
        printf("q%d\t|",i);

        for(int j=0;j<n_alphas;j++){
            printf("%s",initial_states[i].transition[j]);
            printf("\t|");

        }
        printf("\n");

    }




  

    strcpy(queue[++front],initial_states[0].q);

    while(front!=-1){
        char str[10];
        strcpy(str, queue[front--]);
        strcpy(final[f++], str);


        printf(" ++poped str is %s++ \n",str);

        sprintf(final_states[fs].q,"%s",str);


        for(int j=0;j<n_alphas;j++){


            char new_state[20] = "";
            printf("** j is %d **",j);


             //build final state
            for(int s =0; str[s]!= '\0' ; s++){
                int token = str[s] - '0' ;
                printf("for %d: ",token);


                    strcat(new_state,initial_states[token].transition[j]);


                    printf("|| transition %d - %d - %s  ||" ,token,j,new_state);
                    sprintf(final_states[fs].transition[j],"%s",new_state);
                    




                // printf("|new state: %s|",new_state );
            }

            

            
            if(!final_exist(new_state)){
                front = front +1;
                strcpy(queue[front],new_state);
                printf(" **queue is %s** ",queue[front]);
            //    display();

            }

        }

        fs++;

        printf("\n------------\n");

    }

    printf("\n------------\n");
    printf("fs : %d\n",fs);

    printf("state\t|0\t|1\t|\n");
    for(int i = 0;i<fs;i++){
        printf("q%s\t|",final_states[i].q);

        for(int j=0;j<n_alphas;j++){
            printf("%s",final_states[i].transition[j]);
            printf("\t|");

        }
        printf("\n");

    }

     
}