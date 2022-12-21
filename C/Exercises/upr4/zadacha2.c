#include<stdio.h>

/* Да се напише програма, която проверява дали между елементите на редицатa
a0,a1, ...,an са изпълнени релациите:a0 < a1 > a2 < a3…

(въвеждат се N и елементите на редицата) */


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
