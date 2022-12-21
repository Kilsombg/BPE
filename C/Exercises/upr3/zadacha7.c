#include<stdio.h>

/* ������� ������ �� ��������� n ���������. ��� ��� ����� ������� ��� ���� ���������:

�����. ������� �����: 0.70 ��. ������ ������: 0.79 ��. / ��. ����� ������: 0.90 ��. / ��.

�������. ������ / ����� ������: 0.09 ��. / ��. ���� �� �� �������� �� ���������� ������� 20 ��.

����. ������ / ����� ������: 0.06 ��. / ��. ���� �� �� �������� �� ���������� ������� 100 ��.

�������� ��������, ����� ���� ���� ��������� n � ������ �� ���� (���-D ��� ���-N), �������� �� �����������,
 � ��������� ������ �� ���-������� ���������.  */

 int isDay(char);
 void taxi(int, char);
 void bus(int);
 void train(int);

 int main(void)
 {
     int n;
     char p;

     scanf("%d",&n);
     scanf("%c",&p);

    if(n>=100) train(n);
    else if(n >= 20) bus(n);
        else taxi(n,p);
     return 0;
 }

 void taxi(int km, char period)
 {
     float cena = 0.7;
     if(isDay(period)) cena += km*0.79;
     else cena += km*0.9;

    printf("taxi cena: %g", cena);
 }

 void bus(int km)
 {
     float cena = km*0.09;

     printf("bus cena: %g",cena);

 }

 void train(int km)
 {
     float cena = km*0.06;

     printf("train cena: %g",cena);
 }

 int isDay(char period)
 {
     return period == 'D';
 }
