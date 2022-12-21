#include <stdio.h>

int min(int a[])
{
    int i,min = a[0];
    int size = sizeof(a) / sizeof(int);
    for(i=1; i<size;i++)
        if(a[i] < min) min = a[i];

    return min;
}

int main(void)
{
    int a[] = {5,4,-6,2,10};

    printf("min = %d", min(a));
}

// руски паметник - Кабиле Тех 24
