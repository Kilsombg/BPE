#include<stdio.h>

/* ����� ������ �� ����� ����� � ��������� �������� �����, �� ������ ��������.
 �� �� ������ ��������, ����� ������ �������� � ��������� �� ���-������� ��������
  � ����� �������� ��� �������� ��� ��������� �����(�������� �� N � ������ ����� �� �����������). */

  int main(void)
  {

  int N,i,count=0,maxcount=1,k;
  printf("n = ");
  scanf("%d", &N);

  int a[N];

  for(i=0;i<N;i++) {printf("a[%d] = ", i);
  scanf("%d", &a[i]);}

  for(i=1;i<N;i++)
  {
      /* ��������� �� ���������� */
      if(a[i] == a[i-1])
      {
          count++;
      }

      /* �������� ���� ��� ��-������ �������� */
      if(count > maxcount)
      {
          maxcount = count;
          k = i-count;
      }

      /* �������� �� count */
      if(a[i] != a[i-1]) count = 0;
  }

  printf("%d count and %d index", ++maxcount, k);

  return 0;
  }
