#include<stdio.h>

/* �������� ��������, ����� �������� ����� �� N �������� �
������ ���� �� ����������. ��������� ���� ���������� �����. */


int main(void)
{
    int N,i,tmp;
  printf("n = ");
  scanf("%d", &N);

  int a[N];

  for(i=0;i<N;i++) {printf("a[%d] = ", i);
  scanf("%d", &a[i]);}

    for(i=0;i<N/2;i++)
    {
        tmp = a[i];
        a[i] = a[N-1-i];
        a[N-1-i] = tmp;
    }


    for(i=0;i<N;i++) printf("%d ", a[i]);

    return 0;
}
