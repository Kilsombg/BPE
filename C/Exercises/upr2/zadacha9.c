#include<stdint-gcc.h>

/* По въведени параметри за лице на трапец пресметнете лицето му.  */

int main(void){
    float a,b,h;
    puts("base1: ");
    scanf("%f",&a);

    puts("base2: ");
    scanf("%f",&b);

    puts("height");
    scanf("%f",&h);
    printf("S = %f", (a+b)*h/2);
return 0;}
