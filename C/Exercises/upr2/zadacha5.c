#include <stdio.h>

/*�������� ��������, ����� ���������� ��
�������� �� ����������� ������ � ��,��,�� � �.
 �������� �������� ��������� �� �������� � �����������. */

 int main(void)
 {
     float i,sm;
     puts("How much inches?");
     scanf("%f",&i);
     sm = i*2.54;
     printf("%g inches = %g mm\n",i, sm*10);
     printf("%g inches = %g sm\n",i, sm);
     printf("%g inches = %g dm\n",i, sm/10);
     printf("%g inches = %g m",i, sm/100);

     return 0;
 }
