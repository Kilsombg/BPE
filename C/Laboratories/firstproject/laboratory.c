#include<stdio.h>
#include<math.h>

/* ����������� 2 */


// int main(void){
    /* �� �������� ������� �� ASCII ��������� */
    /*
    for(int i=0; i<=5; i++) printf("%c\t", i+48);
    printf("\n");
    for(char i='A'; i<='Z'; i++) printf("%c %c   ", i, i+32);
        */


    /* �� �� ������ ������ �� ������������ */
    /*
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d", a*b); */


    /* �������� �������� */
    /* NOT, AND, OR, XOR, SHIFT LEFT, SHIFT RIGHT
    NOT -> ~
    AND -> &
    OR -> |
    XOR -> ^
    SHIFT LEFT -> <<
    SHIFT RIGHT -> >>
    */

/*
float d;
printf("enter d");
scanf("%f", d);
printf("%f", 3.14*d); */

/* swap two variables withouth temporary */
/*
int a = 3, b = 2;
a = a-b;
b = a+b;
a = b-a;
printf("%d %d", a,b); */

// return 0;}



/* ����������� 3 */


// int main(void){

/* for ����� */
/*
    int i;
    for (i=0; i<=10; ++i) printf("%d",i);
*/

/*
������ 1 : �� �� ������� �� ������������ ���� ����������� ����� � �� �� ������ ���������, ��� �� � ��-������ �� 6.
*/
/*
	int num;
	scanf("%d", &num);
	if(num > 6) printf("%d is bigger than 6", num);
*/


/*
������ 2: �� �� ������� �� ������������ ���� ����������� ����� � �� �� ������ �� ������ ���������,
            ��� ��������� �� ��������� �� � 8 � ��-����� �� 4.
*/
/*
int num;
scanf("%d", &num);
if(num % 8 > 4) printf("%d %% 8 > 4", num);
*/


/* ������ 3: �� �� ������� �� ������������ ���� ����� �� 1 �� 7 � �� �� ������ �� ������ ��� ��� �� ���������
            ����������� �� ���� �����. �� �� �������� ������, ������ �� � �������� ������� �����.
*/

/*
char day;
scanf("%d",&day);
switch(day)
{
    case 1:
        printf("Monday");
        break;
        case 2:
        printf("Tuesday");
        break;
        case 3:
        printf("Wednesday");
        break;
        case 4:
        printf("Thursday");
        break;
        case 5:
        printf("Friday");
        break;
        case 6:
        printf("Saturday");
        break;
        case 7:
        printf("Sunday");
        break;
    default:
        printf("Wrong number... please write number between 1 and 7");
}
*/


/*
������ 4: �� �� ������ ��������, ����� ������� �� ������������ ��� ���� ����� � ������� ������ �� ������� �����
            ���� ��� �����. ���������� ����� �� ������������ �� � ������������ �� �� � ��� ��-�����, ��-������.

����: 2 7

�����: 18 ��������� 3+4+5+6 = 18
*/
/*
int a,b,tmp, sum=0;
scanf("%d %d", &a, &b);
if(b<a)
{
    tmp=a; a=b; b=tmp;
}

for(a++;a<b;a++) sum += a;
printf("%d", sum);
*/

/*
������ 5: �� �� ������ ��������, ����� ������� �� ������������ ��� ����� � ������� ������
            �� ������� ����� � �������������� �� ���������, ����� �� ������� ����� ���� ��� �����.
*/

/*
int a,b,tmp, evenSum=0, oddSum=1;
scanf("%d %d", &a, &b);
if(b<a) // make a = min, and b = max
{
    tmp=a; a=b; b=tmp;
}

for(a++;a<b;a++)
    if(a % 2 == 0) evenSum += a;
        else oddSum *= a;

printf("Sum of even numbers is %d\n", evenSum);
printf("Product of odd numbers is %d", oddSum);
*/

/*
������ 6: �� �� ������ ��������, ����� ������� �� ������������ ���� ���� ����� � ������� ������� ��������:

1

2 2

3 3 3
*/

/*
int i,j,num;
scanf("%d", &num); printf("\n");
for(i=1; i<=num; i++)
{
    for(j=1; j<=i; j++) printf("%d ", i);
    printf("\n\n");
}
*/

/* ������ 7: �� �� ������ ��������, ��� ����� �� �������� ��� ����� N � �.
            ���� ���� �� �������� ��� N ����� � �� ������� ����� �� �������,
            ����� �� ��-������ �� K � �� ����� �� 3.
*/
/*
int i, n, k, num, count = 0;
scanf("%d %d", &n, &k);
for(i=0; i<n; i++)
{
    scanf("%d", &num);
    if(num > k && num % 3 == 0) count++;
}
printf("count is %d", count);
*/


/* ������ 8: �� �� ������ ��������, ����� ������� �� ������������ ��� ������ �����
                � ������� ����������� �� ������ f(x) = x*x-4 �� ������ ��������� � ������� ��������.
                �������� �� ��������� � 0.01
*/
/*
double a,b;
scanf("%lf %lf", &a, &b);
for(;a<b;a+=0.01) printf("f(%lf) = %lf \n", a, a*a-4.);
*/

    //return 0;}



    /* ����������� 4 */
    /* Functions */


/* ������ 1: �� �� ������� ������ �� 1-�������, 2-������������, 3-����. ���������� � ��������� ���� ������� */
/*
float cvadrat(float);
float prav(float, float);
float pravTri(float, float);
float okr(float);

int main(void)
{
    int code;
    printf("Code: ");
    scanf("%d", &code);

    switch(code)
    {
        float a,b;
        float ret;
    case 1:
        scanf("%f", &a);
        ret = cvadrat(a);
        printf("%f", ret);
        break;
    case 2:
        scanf("%f%f", a,b);
        printf("%f",prav(a,b));
        break;
    case 3:
        scanf("%f%f", &a,&b);
        printf("%f",pravTri(a,b));
        break;
    case 4:
        scanf("%f",&a);
        printf("%f",okr(a));
        break;
    default: printf("Wrong");
    }
}

float cvadrat(float a)
{
    return a*a;
}
float prav(float a, float b)
{
    return a*b;
}
float pravTri(float a, float b)
{
    return a*b/2;
}
float okr(float a)
{
    return M_PI*a*a;
}

*/





