#include<stdio.h>

/* Дадена е матрица NxM запълнена с цели числа.
Разменете редовете с най-голям и най-малък елемент. */

int main(void)
{
     int i,j,N,M;
    int max, min, maxI, minI;

     printf("N = ");
    scanf("%d", &N);
    printf("M = ");
    scanf("%d", &M);

     /* Defining the array */
    int a[N][M];

    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
        {
            scanf("%d", &a[i][j]);
        }

        max = min = a[0][0];
        maxI = minI = 0;
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
    {
        if(a[i][j] > max) {max = a[i][j]; maxI = i;}
        if(a[i][j] < min) {min = a[i][j]; minI = i;}
    }

    int tmp;
    for(j=0; j<M; j++)
    {
        tmp = a[maxI][j];
        a[maxI][j] = a[minI][j];
        a[minI][j] = tmp;
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
            printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}
