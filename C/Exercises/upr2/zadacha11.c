#include<stdio.h>

/* �� ������ ������������ �� ��� ������������ ����� �� ������������ ���� ����� � � �,
 �������� ������ �� �������������, ����� � ��������� �� ����� �����. */

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
