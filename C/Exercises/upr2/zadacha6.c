#include <stdio.h>

/* �������� ��������, ����� ���� ������� �� ������� �� ������ � �� �������� � ������� �� ���������  */

int main(void)
{
    float C,F;
    scanf("%f",&C);
    F = C*9/5 + 32;
    printf("%gC = %gF",C,F);
    return 0;
}
