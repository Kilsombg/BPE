#include<stdio.h>

/* Да се напише програма, която чете 3 числа и отпечатва дали са еднакви (yes / no). */

int main(void)
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

    if(a==b && a==c) printf("yes");
    else printf("no");

    return 0;
}
