#include<stdio.h>

/* ƒадена е редица с N цели числа. ƒа се намери K-ти€ по големина елемент в редицата.  */

int main(void)
{
    int N,i,j,tmp,k;
  printf("n = ");
  scanf("%d", &N);

  printf("k = ");
  scanf("%d", &k);

  int a[N];

  for(i=0;i<N;i++) {printf("a[%d] = ", i);
  scanf("%d", &a[i]);}

    for(i=0;i<N-1;i++)
        for(j=0;j<N-i-1;j++)
            if(a[j] < a[j+1]) {tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp;}


printf("%d ", a[k]);
    return 0;
}
