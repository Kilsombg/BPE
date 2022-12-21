#include <stdio.h>
#include <string.h>

/* ���������� ���� �� ���������� �������� �� ���, �� �� ����� ������ �� ������ �������� �� ������������,
 ����� �� �������� � �������� ��������:

���� � 13,99; ���� �� 8 ������ � 42.00; �������� �� 6 ���� � 5,98; �������� �� 6 ����� � ������� � 21.02.

�� ������������ �� �������� ���� �� �������. ������� ������ � ����, ����� �� ������� � �����
���������� �� ������� �� ��������� �� ������� PARTY!. �������� ����� ���� � �������� �� �������
���������� � ����� ��� ���� ������ �� ���� �� �� ���� �� ��������� ������ ����� � ������ ����� ��
���� ����, �� ����� �� ���� � �� ���������� � ���� � �������.

������:

10

Table

Chair

Chair

Chair

Cups

Cups

Dishes

PARTY!

�����:

116,95

1 Table

7 Chairs

1 Dishes

(��������� � ���������� ���� �� �� �������� 116,95. ��� �������� ���� ����, � �� �������� �� 10 ������ �� ����� 2 ����.
 ��� ��������    3 ����� � ����� �� ��� 7 �� �� ���� ����� �� ���� �� ����. ���������, ����� �� ����� �� ��� 4 ����,
 ����� ����� ���������� �� ��� ���� ��������).  */

 #define N 10


void print(int count, int cpk, int ppl, char pr[]);
char *mkPr(int count, char pr[]);

 int main(void)
 {
     char inv[N];
     int ppl;
     double money = 0;
     int cT, cCh, cCu, cD;
     cT = cCh = cCu = cD = 0;

     scanf("%d", &ppl);


     while(1)
     {
         scanf(" %[^\n]s", &inv);
         if(!strcmp(inv, "PARTY!")) break;

         if(!strcmp(inv,"Table")) cT++;
         else if(!strcmp(inv,"Chair")) cCh++;
         else if(!strcmp(inv,"Cups")) cCu++;
         else if(!strcmp(inv,"Dishes")) cD++;
     }

     money = cT * 42 + cCh * 13.99 + cCu * 5.98 + cD * 21.02;

     printf("%lf\n", money);
     print(cT, 8, ppl, "Table");
     print(cCh, 1, ppl, "Chair");
     print(cCu, 6, ppl, "Cups");
     print(cD, 6, ppl, "Dishes");
 }


 void print(int count, int cpk, int ppl, char pr[])
 {
     int nT;
     if(count * cpk < ppl) {
        nT = (ppl - count * cpk) / cpk;
        if(cpk != 1) nT++;


       printf("%d %s", nT, pr);
       if(nT > 1 && strcmp(pr,"Cups") && strcmp(pr, "Dishes")) printf("s\n");
       else printf("\n");

     }
 }
