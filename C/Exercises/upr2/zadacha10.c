#include<stdio.h>
#include<math.h>

/* ��� �������� ������� �� ���� ��������� ���������� ��
 ������, ��������, �������� � ���������� �� ���� ����.   */

 int main(void){
     int deg;
     float rad;
     scanf("%d",&deg);
     rad = deg*M_PI/180;
     printf("sin = %lf\n",sin(rad));
     printf("cos = %lf\n",cos(rad));
     printf("tg = %lf\n",sin(rad)/cos(rad));
     printf("cotg = %lf\n",cos(rad)/sin(rad));
 return 0;}
