#include<stdio.h>
#include<math.h>

/* �������� ��������� �� ������� � �������  */
int main(void){
    float deg, rad;
    scanf("%f",&deg);

    rad = deg*M_PI/180;
    printf("%f deg = %f rad",deg,rad);
return 0;}
