#include<stdio.h>

/* �������� �������, ����� �������� ��� ����� � ����� �� � �������� �� ���.
 ��������� ������ � �� �� -  �������. �������������� �������� �� ��������� ����
������ ��������� ����� �� ��������� �� 0 � �������� ��� � �������� �������� � ���-������� �������� �����.  */


int main(void){
int a=1;
int max = -99999, min = 99999;
while(1)
{
    if(!a) break;
    scanf("%d",&a);
    max = bigger(a,max);
    min = smaller(a,min);
}
printf("max = %d\n", max);
printf("min = %d", min);
return 0;}

int bigger(int a, int b)
{
    if(a>=b) return a;
    else return b;
}

int smaller(int a, int b)
{
    if(a<=b) return a;
    else return b;
}
