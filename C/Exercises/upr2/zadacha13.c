#include<stdio.h>
#include<math.h>

/* ������ ���� ��� ����������� ������ w �� h �����. ������ � ��������� �� ��� ����� � ���� � �����,
 � ������� ������������� �� �������. � ������ � � ������� ���� ��� ������ � ����. � ������� ���� ��
  ������ ��� ������ ������ �����. � �������� ���� �� ������ ��� ������� � ������ �� �������������.
  ���� ������� ����� ����� 70 �� 120 cm. ��������� � ����� ���� 100 cm. ��������� �, �� ������ ��������
   ����� �� ���� ����� 1 ������� �����, � ������ ��������� �� ����� ����� 2 ������� �����.
   �������� ��������, ����� ������� ��������� �� �������� ���� � ��������� ���� ������� �����
   � ��� ��� ��������� ������������.

����: 15 8,9   �����: 129

���� 8,4 5,2 �����: 39 */

int main(void){
    double w,h;
    double rmw = 0.7, rmh = 1.2; /* ������� ����� 70 �� 120 �� */
    double countw, counth;

    printf("width: ");
    scanf("%lf",&w);
    printf("height: ");
    scanf("%lf",&h);

    w -= 1; /* ������� */
    countw = w / rmw;
    counth = h / rmh;
printf("\ncountw = %lf\tcounth = %lf\n", countw, counth);
    countw = floor(countw) - 3;
    counth = floor(counth);
printf("\ncountw = %lf\tcounth = %lf\n", countw, counth);

    double res;
    /*res = countw*counth - 1 - 2; */
    res = countw*counth;
    printf("%lf",res);

return 0;}
