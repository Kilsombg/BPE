#include<stdio.h>

/* ?????? ? ???? V ??? ??? ????? ?? ????? ?? ?????.
????? ????? ??? ????????? ????? (??????? ???? ???????? ???? ???? ????? ?? ???? ???).
?????????? ????? ??????? ???????????? ? ?????? ?? N ????. ???????? ????????, ????? ???????
??????????? ?? ???????, ? ???????, ?????? ?????????? ?? ?????. */


int main(void){
float V,d1,d2,N;
scanf("%f",&V);
scanf("%f%f",&d1,&d2);
scanf("%f",&N);

float sus;
sus = (d1*N+d2*N)*100 / V;
if(sus > 100) sus = 100;
printf("%g%%",sus);
return 0;
}
