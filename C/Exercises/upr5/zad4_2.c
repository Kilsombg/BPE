#include<stdio.h>

/*  В училището на Ели има 1 ≤ N ≤ 100,000 човека.
    Някои от тях се познават с други, като Ели знае,
    че съществуват 1 ≤ M ≤ 1,000,000 такива приятелства.
    Тя иска да напише програма, която бързо отговаря кои
    са приятелите на даден човек. Ако хората се подават с
    номера като цяло число, както и приятелите им изведете
    при поискан човек колко приятели има.
    (ако 1 е приятел с 3 то и 3 е приятел с 1). */

     void mkFriend(int * pr, int fr ,int count);

    int main(void)
    {
        int N, M;
        int i,j;
        int pr1, pr2;


        do{
            printf("N = "); /* хора */
            scanf("%d", &N);
            } while(N > 100000 || N < 1);

        do{
            printf("M = "); /* приятелски връзки */
            scanf("%d", &M);
            } while(N > 100000000 || N < 1);

        int size[N];
        for(i=0;i<N;i++)
            size[i] = 1;

        /* масив от N елемента */
        int ** pr;
        pr = (int **)malloc(N*sizeof(int *));
        if(pr == NULL) exit(1);

        /* вграден масив */
        for(i=0; i<N; i++)
        {
            pr[i] = (int *)calloc(1,sizeof(int));
            if(pr[i] == NULL) exit(1);
        }


        /* създаване на приятелства */

        puts("Write the friend links:");
        for(i=0; i<M; i++){
            do{
            scanf("%d", &pr1);
            scanf("%d", &pr2);}
                    while(pr1>N || pr2>N);

           mkFriend(&pr[pr1-1], pr2, size[pr1-1]);
           mkFriend(&pr[pr2-1], pr1, size[pr2-1]);
        }

        /* принтиране на връзките */
        for(i=0; i<N; i++)
        {
            printf("\n");
            printf("%d: ", i+1 );
            for(j=0; j < size[i]; j++)
            {
                printf("%d ", pr[i][j]);
            }
        }

        return 0;
    }


    void mkFriend(int * pr, int fr ,int count)
    {
        /* ако няма връзка с друг не се променя размера */

        if(pr[0]){
            pr = (int *)realloc(pr, (++count)*sizeof(int));
            if(pr == NULL) exit(1);
           }

        pr[count-1] = fr;
    }
