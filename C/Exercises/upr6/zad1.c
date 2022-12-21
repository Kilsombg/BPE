#include <stdio.h>
#include <string.h>

/* Харалампий иска да организира рождения си ден, но за целта трябва да закупи инвентар за провеждането,
 който се изразява в следните предмети:

Стол – 13,99; Маса за 8 човека – 42.00; комплект от 6 чаши – 5,98; комплект от 6 чинии с прибори – 21.02.

От клавиатурата се въвеждат броя на гостите. Следват редове с неща, които до момента е купил
Харалампий за партито до въвеждане на команда PARTY!. Сметнете колко пари е похарчил до момента
Харалампий и колко още неща трябва да купи за да може да реализира своето парти и всички гости да
имат стол, да седят на маса и да разполагат с чаша и прибори.

Пример:

10

Table

Chair

Chair

Chair

Cups

Cups

Dishes

PARTY!

Изход:

116,95

1 Table

7 Chairs

1 Dishes

(пояснение – поръчаните неща са на стойност 116,95. Има закупена една маса, а за сядането на 10 човека са нужни 2 маси.
 Има закупени    3 стола – нужни са още 7 за да може всеки да седи на стол. Приборите, които са нужни са още 4 броя,
 което значи закупуване на още един комплект).  */

 #define N 10


void print(int count, int cpk, int ppl, char pr[]);
char *mkPr(int count, char pr[]);

 int main(void)
 {
     char inv[N];
     int ppl;
     double money = 0;
     int cT, cCh, cCu, cD;
     cT = cCh = cCu = cD = 0;

     scanf("%d", &ppl);


     while(1)
     {
         scanf(" %[^\n]s", &inv);
         if(!strcmp(inv, "PARTY!")) break;

         if(!strcmp(inv,"Table")) cT++;
         else if(!strcmp(inv,"Chair")) cCh++;
         else if(!strcmp(inv,"Cups")) cCu++;
         else if(!strcmp(inv,"Dishes")) cD++;
     }

     money = cT * 42 + cCh * 13.99 + cCu * 5.98 + cD * 21.02;

     printf("%lf\n", money);
     print(cT, 8, ppl, "Table");
     print(cCh, 1, ppl, "Chair");
     print(cCu, 6, ppl, "Cups");
     print(cD, 6, ppl, "Dishes");
 }


 void print(int count, int cpk, int ppl, char pr[])
 {
     int nT;
     if(count * cpk < ppl) {
        nT = (ppl - count * cpk) / cpk;
        if(cpk != 1) nT++;


       printf("%d %s", nT, pr);
       if(nT > 1 && strcmp(pr,"Cups") && strcmp(pr, "Dishes")) printf("s\n");
       else printf("\n");

     }
 }
