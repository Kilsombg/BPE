#include<stdio.h>

/*  В училището на Ели има 1 ≤ N ≤ 100,000 човека.
    Някои от тях се познават с други, като Ели знае,
    че съществуват 1 ≤ M ≤ 1,000,000 такива приятелства.
    Тя иска да напише програма, която бързо отговаря кои
    са приятелите на даден човек. Ако хората се подават с
    номера като цяло число, както и приятелите им изведете
    при поискан човек колко приятели има.
    (ако 1 е приятел с 3 то и 3 е приятел с 1). */

    int main(void)
    {
        int N,M;
        int i,j;
        int p1,p2;
        int tmp;

        printf("M : ");
        scanf("%d",&N);
        printf("N : ");
        scanf("%d",&M);

        /* нулиране на масива */
        int a[N][M];
        for(i=0; i<N; i++)
            for(j=0; j<M; j++)
                a[i][j] = 0;


        /* сприятеляване */
        for(i=0; i<M; i++)
        {
            do{
            puts("link a friends:");
            scanf("%d", &p1);
            scanf("%d", &p2);} while(p1>N || p2>N);

            tmp = 0;
            while(a[p1-1][tmp]) tmp++;
            a[p1-1][tmp] = p2;
            tmp = 0;
            while(a[p2-1][tmp]) tmp++;
            a[p2-1][tmp] = p1;
        }

        /* извеждане на ненулеви елементи от масива*/
        /*
        printf("\nList of friends:\n");
        for(i=0;i<N; i++){
                printf("%d : ", i+1);
            for(j=0;a[i][j] && j<M; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        } */

        /* извеждане на приятелите */
        printf("\nWhich person you want?\n");
        scanf("%d",&tmp);
        for(i=0; a[tmp-1][i]; i++) printf("%d ", a[tmp-1][i]);
    return 0;
    }
