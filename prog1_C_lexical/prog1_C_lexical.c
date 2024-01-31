/*1. Design and implement a lexical analyzer using C language to recognize all
valid tokens in the input program. The lexical analyzer should ignore
redundant spaces, tabs and newlines. It should also ignore comments*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[50][50] = {"int", "float", "if", "while"};

void main()
{
    int states[50];
    int s = 0;
    int keys[50];
    int k=0;
    char buff[100];
    FILE *fp;

    fp = fopen("program.c", "r");

    int inside_comment = 0; // Flag to track if we're inside a comment block

    while (fscanf(fp, "%s", buff) == 1)
    {
        // Check if we're inside a comment block
        if (inside_comment)
        {
            if (strstr(buff, "*/") != NULL)
            {
                inside_comment = 0; // End of comment block
            }
        }
        else if (strstr(buff, "/*") != NULL)
        {
            inside_comment = 1; // Start of comment block
        }
        else if (strstr(buff, "//") != NULL)
        {
            break;
        }
        else
        {
            if (isalpha(buff[0]))
            {
                states[s++] = 1;

                int flag = 1;

                for (int i = 0; i < 10; i++)
                {
                    if (strcmp(keywords[i], buff) == 0)
                    {
                        states[s++] = 2;
                        keys[k++] = i;
                        // printf("<keyword : %s>", keywords[i]);
                        flag = 0;
                    }
                }
                int i = 0;
                while (buff[i] != '\0')
                {
                    if (!isalnum(buff[i]))
                    {
                        flag = 0;
                    }
                    i++;
                }
                if (flag == 1)
                {
                    states[s++] = 3;

                    // printf("<identifier>");
                }
            }
            else if (isdigit(buff[0]))
            {
                int flag = 1;
                int i = 0;
                while (buff[i] != '\0')
                {
                    if (!isdigit(buff[i]))
                    {
                        flag = 0;
                    }
                    i++;
                }
                if (flag == 1)
                {
                    states[s++] = 4;
                    // printf("<number>");
                }
            }
            else if (strcmp(buff, "=") == 0)
            {
                states[s++] = 5;
                // printf("<assignment operator>");
            }
            else if (strcmp(buff, ">") == 0)
            {
                states[s++] = 6;
                // printf("<greater than operator>");
                if (buff[1] == '=')
                {
                    states[s++] = 7;
                    // printf("<greater than or equal to operator>");
                }
            }
            else if (strcmp(buff, "<") == 0)
            {
                states[s++] = 8;
                // printf("<less than operator>");
                if (buff[1] == '=')
                {
                    states[s++] = 9;
                    // printf("<less than or equal to operator>");
                }
            }
            else if (strcmp(buff, "+") == 0)
            {
                states[s++] = 10;
                // printf("<plus operator>");
            }
            else if (strcmp(buff, "-") == 0)
            {
                states[s++] = 11;
                // printf("<plus operator>");
            }
            else if (strcmp(buff, "*") == 0)
            {
                states[s++] = 12;
                // printf("<plus operator>");
            }
            else if (strcmp(buff, "/") == 0)
            {
                states[s++] = 13;
                // printf("<plus operator>");
            }
            else if (strcmp(buff, ";") == 0)
            {
                states[s++] = 14;
                // printf("\n");
            }
        }
    }
    fclose(fp);

    int r = 0;

    for (int i = 0; i < s; i++)
    {

        switch (states[i])
        {
        case 2:
            printf("<keyword %s>",keywords[keys[r++]]);
            break;
        case 3:
            printf("<identifier>");
            break;
        case 4:
            printf("<number>");
            break;
        case 5:
            printf("<assignment operator>");
            break;
        case 6:
            printf("<greater than operator>");
            break;
        case 7:
            printf("<greater than or equal to operator>");
            break;
        case 8:
            printf("<less than operator>");
            break;
        case 9:
            printf("<less than or equal to operator>");
            break;
        case 10:
            printf("<+ operator>");
            break;
        case 11:
            printf("<- operator>");
            break;
        case 12:
            printf("<* operator>");
            break;
        case 13:
            printf("</ operator>");
            break;
        case 14:
            printf("\n");
            break;
        default:
            break;
        }
    }
}
