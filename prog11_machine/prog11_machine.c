#include<stdio.h>
#include<stdio.h>
#include<string.h>
void main()
{
  printf("Reuben Dinny\nCSE Gamma\nU2003166\n\n");

 char icode[10][30],str[20],opr[10];
 int i=0;
 printf("\n Enter the set of intermediate code (terminated by exit):\n");
do
 {
   scanf("%s",icode[i]);
 }while(strcmp(icode[i++],"exit")!=0);
 printf("\n 8086 Assembly Code");
 printf("\n************************\n");
 i=0;
 do
 {
   strcpy(str,icode[i]);
  switch(str[3])
  {
    case '+': strcpy(opr,"ADD");
              break;
    case '-': strcpy(opr,"SUB");
              break;
    case '*': strcpy(opr,"MUL");
              break;
    case '/': strcpy(opr,"DIV");
              break;
   }
  printf("\tMov %c,R%d\n",str[2],i);
  if(str[3] != '\0'){
  printf("\t%s %c,R%d\n",opr,str[4],i);
 }
  printf("\tMov R%d,%c\n",i,str[0]);
  }while(strcmp(icode[++i],"exit")!=0);
}
