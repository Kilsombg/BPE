#include<stdio.h>

/* По дадени координатите на два срещуположни ъгъла на правоъгълник чрез точки А и Б,
 намерете лицето на правоъгълника, който е ограничен от двете точки. */

 int main(void){
     int Ax,Ay,Bx,By;
     int a,b;
     puts("A : ");
     scanf("%d%d",&Ax,&Ay);
     puts("B : ");
     scanf("%d%d",&Bx,&By);

     a = abs(Bx-Ax);
     b = abs(By-Ay);
     printf("S = %d", a*b);
 return 0;}
