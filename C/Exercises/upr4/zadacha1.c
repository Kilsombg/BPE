#include<stdio.h>

/* Всяка редица от равни числа в едномерен сортиран масив, се нарича площадка.
 Да се напише програма, която намира началото и дължината на най-дългата площадка
  в даден сортиран във възходящ ред едномерен масив(въвеждат се N и самият масив от потребителя). */

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
      /* формиране на площадката */
      if(a[i] == a[i-1])
      {
          count++;
      }

      /* проверка дали има по-голяма площадка */
      if(count > maxcount)
      {
          maxcount = count;
          k = i-count;
      }

      /* нулиране на count */
      if(a[i] != a[i-1]) count = 0;
  }

  printf("%d count and %d index", ++maxcount, k);

  return 0;
  }
