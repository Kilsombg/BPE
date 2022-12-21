#include<stdio.h>

/* Напишете конвертор от левове в долари, евро и паундове  */

int main(void){
    float lv;
    scanf("%f",&lv);
    printf("dollars: %f\n",lv*0.56);
    printf("euro: %f\n",lv*0.51);
    printf("pounds: %f\n",lv*0.43);
return 0;}
