/*
a=b/d+c*e-f/g+q
a=b+c+d


*/
char z = 'z';

#include <stdio.h>
#include <string.h>

char str[100];

void main()
{

    printf("Enter the expression: ");
    scanf("%s", str);

    while (strlen(str) > 3)
    {
        int flag = 0;

        if (flag != 1)
        {
            for (int i = 0; i < strlen(str); i++)
            {
                if (str[i] == '*' || str[i] == '/')
                {
                    printf("%c=%c%c%c\n", z, str[i - 1], str[i], str[i + 1]);

                    str[i - 1] = z;

                    for (int j = i; str[j] != '\0'; j++)
                    {
                        str[j] = str[j + 2];
                    }
                    z--;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag != 1)
        {
            for (int i = 0; i < strlen(str); i++)
            {
                if (str[i] == '+' || str[i] == '-')
                {
                    printf("%c=%c%c%c\n", z, str[i - 1], str[i], str[i + 1]);

                    str[i - 1] = z;

                    for (int j = i; str[j] != '\0'; j++)
                    {
                        str[j] = str[j + 2];
                    }
                    z--;
                    flag = 1;

                    break;
                }
            }
        }
    }
}

// #include <stdio.h>
// #include <string.h>

// char temp_v = 'Z';

// void main()
// {
//     char str[100];

//     printf("Enter the expression: ");
//     scanf("%s", str);

//     while (strlen(str) > 3)
//     {
//         int flag = 0;

//         if (flag != 0)
//         {
//             for (int i = 0; i < strlen(str); i++)
//             {

//                 if (str[i] == '/' || str[i] == '*')
//                 {
//                     printf("%c=%c%c%c\n", temp_v, str[i - 1], str[i], str[i + 1]);

//                     str[i - 1] = temp_v;

//                     for (int j = i; str[j] != '\0'; j++)
//                     {
//                         str[j] = str[j + 2];
//                     }
//                     temp_v--;
//                     flag = 1;
//                     break;
//                 }
//             }
//         }

//         if (flag != 0)
//         {
//             for (int i = 0; i < strlen(str); i++)
//             {

//                 if (str[i] == '+' || str[i] == '-')
//                 {
//                     printf("%c=%c%c%c\n", temp_v, str[i - 1], str[i], str[i + 1]);

//                     str[i - 1] = temp_v;

//                     for (int j = i; str[j] != '\0'; j++)
//                     {
//                         str[j] = str[j + 2];
//                     }
//                     temp_v--;
//                     flag = 1;
//                     break;
//                 }
//             }
//         }
//     }
// }