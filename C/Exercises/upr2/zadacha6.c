#include <stdio.h>

/* Напишете програма, която чете градуси по скалата на Целзий и ги превръща в градуси по Фаренхайт  */

int main(void)
{
    float C,F;
    scanf("%f",&C);
    F = C*9/5 + 32;
    printf("%gC = %gF",C,F);
    return 0;
}
