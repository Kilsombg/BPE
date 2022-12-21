#include<stdio.h>

/* Студент трябва да пропътува n километра. Той има избор измежду три вида транспорт:

Такси. Начална такса: 0.70 лв. Дневна тарифа: 0.79 лв. / км. Нощна тарифа: 0.90 лв. / км.

Автобус. Дневна / нощна тарифа: 0.09 лв. / км. Може да се използва за разстояния минимум 20 км.

Влак. Дневна / нощна тарифа: 0.06 лв. / км. Може да се използва за разстояния минимум 100 км.

Напишете програма, която чете броя километри n и период от деня (ден-D или нощ-N), въведени от потребителя,
 и изчислява цената на най-евтиния транспорт.  */

 int isDay(char);
 void taxi(int, char);
 void bus(int);
 void train(int);

 int main(void)
 {
     int n;
     char p;

     scanf("%d",&n);
     scanf("%c",&p);

    if(n>=100) train(n);
    else if(n >= 20) bus(n);
        else taxi(n,p);
     return 0;
 }

 void taxi(int km, char period)
 {
     float cena = 0.7;
     if(isDay(period)) cena += km*0.79;
     else cena += km*0.9;

    printf("taxi cena: %g", cena);
 }

 void bus(int km)
 {
     float cena = km*0.09;

     printf("bus cena: %g",cena);

 }

 void train(int km)
 {
     float cena = km*0.06;

     printf("train cena: %g",cena);
 }

 int isDay(char period)
 {
     return period == 'D';
 }
