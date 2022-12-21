#include<stdio.h>

/* За дадена редица от числа да се намери и отпечата
най-дългата (монотонно) нарастваща (или намаляваща) под редица */

int main(void)
{
    int N, i, k, maxcount=0, count1=0,count2=0; /* 1 - разстяща, 2 - намаляваща */
    scanf("%d", &N);
    int a[N];
    for(i=0;i<N;i++) scanf("%d",&a[i]);

   // int a[] = {4,5,7,7,8,9,6,5,4,3,8,3,9,2,1};
    N = sizeof(a) / sizeof(a[0]);


    for(i=1;i<N;i++)
    {
        /* 1 - разстяща */
        if(a[i] >= a[i-1]) count1++;
        else
        {
            if(count1 > maxcount)
            {
                k= i - ++count1;
                maxcount = count1;
                count1 = 0;
            }
        }

        /* 2 - намаляваща */
        if(a[i] <= a[i-1]) count2++;
        else
        {
            if(count2 > maxcount)
            {
                k= i - ++count2;
                maxcount = count2;
                count2 = 0;
            }
        }

    }


    for(i=k;i<k+maxcount;i++) printf("%d ", a[i]);


    return 0;
}
