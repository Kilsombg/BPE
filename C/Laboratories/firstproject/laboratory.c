#include<stdio.h>
#include<math.h>

/* Лабораторно 2 */


// int main(void){
    /* да изведете цифрите от ASCII таблицата */
    /*
    for(int i=0; i<=5; i++) printf("%c\t", i+48);
    printf("\n");
    for(char i='A'; i<='Z'; i++) printf("%c %c   ", i, i+32);
        */


    /* да се намери лицето на правоъгълник */
    /*
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d", a*b); */


    /* побитови операции */
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



/* Лабораторно 3 */


// int main(void){

/* for цикъл */
/*
    int i;
    for (i=0; i<=10; ++i) printf("%d",i);
*/

/*
Задача 1 : Да се прочете от клавиатурата едно целочислено число и да се изведе съобщение, ако то е по-голямо от 6.
*/
/*
	int num;
	scanf("%d", &num);
	if(num > 6) printf("%d is bigger than 6", num);
*/


/*
Задача 2: Да се прочете от клавиатурата едно целочислено число и да се изведе на екрана съобщение,
            ако остатъкът от делението му с 8 е по-голям от 4.
*/
/*
int num;
scanf("%d", &num);
if(num % 8 > 4) printf("%d %% 8 > 4", num);
*/


/* Задача 3: Да се прочете от клавиатурата едно число от 1 до 7 и да се изведе на екрана кой ден от седмицата
            съответства на това число. Да се предвиди случай, когато не е въведено валидно число.
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
Задача 4: Да се напише програма, която прочита от клавиатурата две цели числа и извежда сумата на числата между
            тези две числа. Въведените числа от клавиатурата не е задължително да са в ред по-малко, по-голямо.

Вход: 2 7

Изход: 18 Обяснение 3+4+5+6 = 18
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
Задача 5: Да се напише програма, която прочита от клавиатурата две числа и извежда сумата
            на четните числа и произведението на нечетните, които се намират между тези две числа.
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
Задача 6: Да се напише програма, която прочита от клавиатурата едно цяло число и изкарва числова пирамида:

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

/* Задача 7: Да се напише програма, при която се въвеждат две числа N и К.
            След това се въвеждат още N числа и се извежда броят на числата,
            които са по-големи от K и се делят на 3.
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


/* Задача 8: Да се напише програма, която прочита от клавиатурата две реални числа
                и извежда стойностите на фукция f(x) = x*x-4 за всички стойности в дадения интервал.
                Стъпката на обхождане е 0.01
*/
/*
double a,b;
scanf("%lf %lf", &a, &b);
for(;a<b;a+=0.01) printf("f(%lf) = %lf \n", a, a*a-4.);
*/

    //return 0;}



    /* Лабораторно 4 */
    /* Functions */


/* Задача 1: Да се изведат лицата на 1-квадрат, 2-правоъгълник, 3-прав. триъгълник и окръжност чрез функции */
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





