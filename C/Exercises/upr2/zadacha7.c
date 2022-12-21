#include<stdio.h>
#include<math.h>

/* Напишете конвертор от градуси в радиани  */
int main(void){
    float deg, rad;
    scanf("%f",&deg);

    rad = deg*M_PI/180;
    printf("%f deg = %f rad",deg,rad);
return 0;}
