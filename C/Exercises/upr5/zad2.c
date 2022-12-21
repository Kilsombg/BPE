#include<stdio.h>

/* ����� � ����� NxM �������� � ���� �����.
�������� �������, ����� ��� ������ �� ���� �����,
 �� ����� � ���-�����. (������ � ����� ����� ����� �� ������ ��,
���, ��� ��� �� �������� �� �������� �� ��������� �� ������ �� 1 ����). */

int main(void)
{
    int i,j,N,M;
    int maxsum = NULL, sum=0, maxI, maxJ;

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


    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
        {
            /* ����� ��� */
            if(i>0){
                if(j>0) sum += a[i-1][j-1];
                sum += a[i-1][j];
                if(j<M-1) sum += a[i-1][j+1];
            }

            /* ������ ��� */
            if(j>0) sum += a[i][j-1];
            if(j<M-1) sum += a[i][j+1];

            /* ����� ��� */
            if(i<N-1){
                if(j>0) sum += a[i+1][j-1];
                sum += a[i+1][j];
                if(j<M-1) sum += a[i+1][j+1];
            }

             /* �������� ������ � ����������� ���� � ��-������ �� ��������� */
        if(sum >= maxsum || maxsum == NULL)
            {
                maxsum = sum;
                maxI = i;
                maxJ = j;
            }
            sum = 0;
        }

        printf("\nMax sum is: %d\nat a[%d][%d]", maxsum, maxI, maxJ);


    return 0;
}
