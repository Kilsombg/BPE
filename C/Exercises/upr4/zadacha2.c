#include<stdio.h>

/* �� �� ������ ��������, ����� ��������� ���� ����� ���������� �� �������a
a0,a1, ...,an �� ��������� ���������:a0 < a1 > a2 < a3�

(�������� �� N � ���������� �� ��������) */


int main(void)
{
   int N,i;
   int flag = 1;
  printf("n = ");
  scanf("%d", &N);

  int a[N];

  for(i=0;i<N;i++) {printf("a[%d] = ", i);
  scanf("%d", &a[i]);}


    for(i=1;i<N;i++)
    {
        if(i%2 && a[i-1] >= a[i]) {flag = 0; break;}
        if(!(i%2) && a[i-1] <= a[i]) {flag = 0; break;}
    }


    if(flag) puts("yes");
    else puts("no");

    return 0;
}
