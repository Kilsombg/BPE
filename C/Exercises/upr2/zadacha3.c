#include <stdio.h>

/* Напишете програма, която отпечатва рамка с размер 10х5 изградена от знак, въведен от потребителя:
Вход:

-

изход:

----------

-          -

-          -

-          -

 ---------- */

 int main(void){
 char c;
 scanf("%c",&c);
 printf("%c%c%c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c,c);
 printf("%c        %c\n",c,c);
 printf("%c        %c\n",c,c);
 printf("%c        %c\n",c,c);
 printf("%c%c%c%c%c%c%c%c%c%c",c,c,c,c,c,c,c,c,c,c);
return 0;}
