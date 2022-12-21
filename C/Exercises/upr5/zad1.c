#include<stdio.h>

/* Даден е двумерен масив NxM запълнен с цели числа.
Проверете дали всеки ред съдържа числа, подредени в нарастващ ред,
а всяка колона съдържа числа подредени в намаляващ ред. */

int main(void)
{
    int N,M,i,j;
    int desO = 1, asO = 1; /* descending and ascending order */
    printf("N = ");
    scanf("%d", &N); /* редове */
    printf("M = ");
    scanf("%d", &M); /* колони */

    /* Defining the array */
    int ar[N][M];

    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
        {
            scanf("%d", &ar[i][j]);
        }


    /* Printing the array */
    for(i=0; i<N; i++)
    {
        puts("");
        for(j=0; j<M; j++)
        {
            printf("%d ", ar[i][j]);
        }
    }

    /* Checking for ascending and descending order */

    /* Ascending */
    for(i=0; i<N; i++)
    {
        for(j=1; j<M; j++)
        {
            if(ar[i][j] < ar[i][j-1]) {asO = 0; break;}
        }
        if(!asO) break;
    }

    /* Descending */
        for(i=0; i<M; i++)
        {
            for(j=1; j<N; j++)
            {
                if(ar[j][i] > ar[j-1][i]) {desO = 0; break;}
            }
            if(!desO) break;
        }

        puts("");
    if(asO) puts("The rows are in ascending order.");
        else puts("The rows are not in ascending order");
    if(desO) puts("The columns are in descending order.");
        else puts("The columns are not in descending order.");
    return 0;
}
