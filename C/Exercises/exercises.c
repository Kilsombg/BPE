/* Упражнение 3 */

// Задача 1

// #include<stdio.h>

/* Напишете функция, която получава две числа и връща по – голямото от тях.
 Направете същото и за по -  малкото. Демонстрирайте работата на функциите като
четете множество числа до въвеждане на 0 и изкарате най – голямото въведено и най-малкото въведено число.  */

/*
int main(void){
int a=1;
int max = -99999, min = 99999;
while(1)
{
    if(!a) break;
    scanf("%d",&a);
    max = bigger(a,max);
    min = smaller(a,min);
}
printf("max = %d\n", max);
printf("min = %d", min);
return 0;}

int bigger(int a, int b)
{
    if(a>=b) return a;
    else return b;
}

int smaller(int a, int b)
{
    if(a<=b) return a;
    else return b;
}
*/


// Задача 2

/* Да се напише програма, която чете час и минути от 24-часово денонощие,
въведени от потребителя, и изчислява колко ще е часът след 15 минути.
Резултатът да се отпечата във формат hh:mm. Часовете винаги са между 0 и 23,
а минутите винаги са между 0 и 59. Часовете се изписват с една или две цифри.
Минутите се изписват винаги с по две цифри, с водеща нула когато е необходимо. */

/*
 int main(void){
int h,m;
scanf("%d %d", &h, &m);

m += 15;

if(m>=60) {m-=60;h++;}
if(h==24) h=0;

printf("%d:%0.2d",h,m);

 return 0;}
*/


// Задача 3
/* Да се напише програма, която чете 3 числа и отпечатва дали са еднакви (yes / no). */

/*
int main(void)
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

    if(a==b && a==c) printf("yes");
    else printf("no");

    return 0;
}
*/

// Задача 4

/* Дадено е цяло число – брой точки. Върху него се начисляват бонус точки по правилата, описани по-долу.
 Да се напише програма, която пресмята бонус точките за това число и общия брой точки с бонусите.

Ако числото е до 100 включително, бонус точките са 5.

Ако числото е по-голямо от 100, бонус точките са 20% от числото.

Ако числото е по-голямо от 1000, бонус точките са 10% от числото.

Допълнителни бонус точки (начисляват се отделно от предходните):

За четно число -> + 1 т.

За число, което завършва на 5 -> + 2 т. */

/*
float bonus(int num);

int main(void)
{
    int num;
    float b;
    scanf("%d",&num);
    b = bonus(num);
    printf("bonus : %g\n",b);
    printf("number+bonus : %g",b+num);
    return 0;
}

float bonus(int num)
{
    float b=0;

    if(num<=100) b += 5;
    if(num>100 && num <=1000) b += 0.2*num;
    if(num>1000) b += 0.1*num;

    if(!(num%2)) b+=1;
    if(num%10==5) b+=2;

    return b;
}*/

// Задача 5

/* Трима спортни състезатели финишират за някакъв брой секунди (между 1 и 50).
 Да се напише програма, която чете времената на състезателите, въведени от потребителя,
  и пресмята сумарното им време във формат "минути:секунди". Секундите да се изведат с водеща нула
  (2 -> "02", 7 -> "07", 35 -> "35") */

  /*
int main(void)
{
    int s1,s2,s3,m;

    scanf("%d",&s1);
    scanf("%d",&s2);
    scanf("%d",&s3);
    s1 += s2+s3;
    m = s1/60; s1 = s1-m*60;
    printf("%d:%0.2d",m,s1);
    return 0;
}
*/


// Задача 6

/* Напишете програма, която проверява дали точка {x, y}
 се намира вътре в правоъгълник {x1, y1} – {x2, y2}.
  Входните данни се четат от конзолата и се състоят от 6 реда,
   въведени от потребителя: десетичните числа x1, y1, x2, y2, x и y (като се гарантира, че x1 < x2 и y1 < y2).
   Една точка е вътрешна за даден правоъгълник, ако се намира някъде във вътрешността
   му или върху някоя от страните му. Отпечатайте “Inside” или “Outside” */


   /*
   int main(void)
   {
       int x1,y1,x2,y2,x,y;
       scanf("%d %d",&x1,&y1);
       scanf("%d %d",&x2,&y2);
       scanf("%d %d",&x,&y);

       if(x1<=x && x<=x2 && y1<=y && y<=y2) printf("Inside");
       else printf("Outside");
       return 0;
   }*/



// Задача 7

/* Студент трябва да пропътува n километра. Той има избор измежду три вида транспорт:

Такси. Начална такса: 0.70 лв. Дневна тарифа: 0.79 лв. / км. Нощна тарифа: 0.90 лв. / км.

Автобус. Дневна / нощна тарифа: 0.09 лв. / км. Може да се използва за разстояния минимум 20 км.

Влак. Дневна / нощна тарифа: 0.06 лв. / км. Може да се използва за разстояния минимум 100 км.

Напишете програма, която чете броя километри n и период от деня (ден-D или нощ-N), въведени от потребителя,
 и изчислява цената на най-евтиния транспорт.  */

 /*
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
*/

// Задача 8

/* Басейн с обем V има две тръби от които се пълни.
Всяка тръба има определен дебит (литрите вода минаващи през една тръба за един час).
Работникът пуска тръбите едновременно и излиза за N часа. Напишете програма, която изкарва
състоянието на басейна, в момента, когато работникът се върне. */


/*
int main(void){
float V,d1,d2,N;
scanf("%f",&V);
scanf("%f%f",&d1,&d2);
scanf("%f",&N);

float sus;
sus = (d1*N+d2*N)*100 / V;
if(sus > 100) sus = 100;
printf("%g%%",sus);
return 0;
}
*/


// Задача 9

/* От лозе с площ X квадратни метри се заделя 40% от реколтата за производство на вино.
 От 1 кв.м лозе се изкарват Y килограма грозде. За 1 литър вино са нужни 2,5 кг. грозде.
  Желаното количество вино за продан е Z литра.

Напишете програма, която пресмята колко вино може да се произведе и дали това количество е достатъчно.
 Ако е достатъчно, остатъкът се разделя по равно между работниците на лозето. */

 /*
int main(void)
{
    float X, Y, li, Z;

    scanf("%f",&X);
    scanf("%f",&Y);
    scanf("%f",&Z);

    li = ((0.4*X) * Y) /2.5;
    if(li >= Z) printf("%g li > %g",li,Z);
    else printf("%gli < %g",li,Z);
    return 0;
}
*/

// Задача 10

/* Дадени са n цели числа в интервала [1…1000].
 От тях някакъв процент p1 са под 200, друг процент p2 са от 200 до 399,
  друг процент p3 са от 400 до 599, друг процент p4 са от 600 до 799 и
   останалите p5 процента са от 800 нагоре. Да се напише програма,
   която изчислява и отпечатва процентите p1, p2, p3, p4 и p5. */

/*
   int main(void)
   {
       int n, c1,c2,c3,c4,c5;
       c1=c2=c3=c4=c5=0;
       int x;
       puts("n=");
       scanf("%d",&n);

       for(int i=0;i<n;i++)
       {
           puts("x = ");
           scanf("%d",&x);

            if(x<200) c1++;
            else if(x<=399) c2++;
                else if(x<=599) c3++;
                    else if(x<=799) c4++;
                        else c5++;
       }

       printf("p1 = %g", (double)c1*100/n);
       printf("p1 = %g", (double)c2*100/n);
       printf("p1 = %g", (double)c3*100/n);
       printf("p1 = %g", (double)c4*100/n);
       printf("p1 = %g", (double)c5*100/n);
       return 0;
   }
*/

// Задача 11

/* Да се напише програма, която прочита от конзолата цяло число n,
въведено от потребителя, и чертае крепост с ширина 2 * n колони и
височина n реда като в примерите по-долу. Лявата и дясната колона във
 вътрешността си са широки n / 2. */

/*
 int main(void)
 {
     int n;
     scanf("%d",&n);
     if(n>3)
     {
         //OP ROW
         // left side
         putchar('/');
         for(int i=0;i<n/2;i++) putchar('^');
         putchar('\\');

         // middle
         int m = n*2 - (n/2) * 2 - 4;  // width - 2n,  left and right sides '^' and left and right '\', '/'
         for(int i=0; i<m;i++) putchar('_');

         // right side
         putchar('/');
         for(int i=0;i<n/2;i++) putchar('^');
         putchar('\\');


         // SIDES
         for(int i=2;i<n-1;i++)
         {
             puts(""); // new line
             putchar('|');
             for(int i=0; i<2*n-2; i++) putchar(' ');
             putchar('|');
         }



         // BOTTOM ROW

          // middle part of the bottom row
         puts("");
         int inMid = n/2+m/4; /* width of the internal parts of the bottom row
         putchar('|');
         for(int i=-1;i<inMid;i++) putchar(' ');
         for(int i=0; i<m/2;i++) putchar('_');
         for(int i=-1;i<inMid;i++) putchar(' ');
         if(n%2) putchar(' ');
         putchar('|');

         puts(""); // new line

         // left side
         putchar('\\');
         for(int i=0;i<inMid;i++) putchar('_');
         putchar('/');

        for(int i=0; i<m/2;i++) putchar(' ');

         // right side
         putchar('\\');
         for(int i=0;i<inMid;i++) putchar('_');
         putchar('/');
     }


     return 0;
 }
*/


// Задача 12
 //Не съм


 /* Упражнение 4 */

 // Задача 1

 /* Всяка редица от равни числа в едномерен сортиран масив, се нарича площадка.
 Да се напише програма, която намира началото и дължината на най-дългата площадка
  в даден сортиран във възходящ ред едномерен масив(въвеждат се N и самият масив от потребителя). */

  /*
  int main(void)
  {

  int N,i,count=0,maxcount=1,k;
  printf("n = ");
  scanf("%d", &N);

  int a[N];

  for(i=0;i<N;i++) {printf("a[%d] = ", i);
  scanf("%d", &a[i]);}

  for(i=1;i<N;i++)
  {
      // формиране на площадката
      if(a[i] == a[i-1])
      {
          count++;
      }

      // проверка дали има по-голяма площадка
      if(count > maxcount)
      {
          maxcount = count;
          k = i-count;
      }

      // нулиране на count
      if(a[i] != a[i-1]) count = 0;
  }

  printf("%d count and %d index", ++maxcount, k);

  return 0;
  }
*/


// Задача 2

/* Да се напише програма, която проверява дали между елементите на редицатa
a0,a1, ...,an са изпълнени релациите:a0 < a1 > a2 < a3…

(въвеждат се N и елементите на редицата) */


/*
int main(void)
{
   int N,i;
   int flag = 1;
  printf("n = ");
  scanf("%d", &N);

  int a[N];

  for(i=0;i<N;i++) {printf("a[%d] = ", i);
  scanf("%d", &a[i]);}


    for(i=1;i<N;i++)
    {
        if(i%2 && a[i-1] >= a[i]) {flag = 0; break;}
        if(!(i%2) && a[i-1] <= a[i]) {flag = 0; break;}
    }


    if(flag) puts("yes");
    else puts("no");

    return 0;
}
*/


// Задача 3
/* Напишете програма, която получава масив от N елемента и
обръща реда на елементите. Изкарайте ново полученият масив. */

/*
int main(void)
{
    int N,i,tmp;
  printf("n = ");
  scanf("%d", &N);

  int a[N];

  for(i=0;i<N;i++) {printf("a[%d] = ", i);
  scanf("%d", &a[i]);}

    for(i=0;i<N/2;i++)
    {
        tmp = a[i];
        a[i] = a[N-1-i];
        a[N-1-i] = tmp;
    }


    for(i=0;i<N;i++) printf("%d ", a[i]);

    return 0;
}
*/


// Задача 4

/* Напишете програма, която получава редица с цели N числа.
 След това получава цяло число К. Отместете всички елементи на
  редицата с K позиции, като използвате правилото за превъртане
  (когато елемент от последна позиция трябва да се измести то той
   трябва да отиде на първа позиция в редицата). */

   /*
 int main(void)
{
    int N,j,i,tmp,k;
  printf("n = ");
  scanf("%d", &N);

// 0 1 2 3 4 5 6 7

  printf("k = ");
  scanf("%d", &k);

  int a[N];

  for(i=0;i<N;i++) {printf("a[%d] = ", i);
  scanf("%d", &a[i]);}


  for(j=0; j<k; j++)
   {
       tmp = a[N-1];

       for(i=N-1;i>0;i--)
       {
           a[i] = a[i-1];
       }

       a[0] = tmp;
   }


  for(i=0;i<N;i++) printf("%d ", a[i]);
  return 0;
}
*/

// Задача 5

/* Дадена е редица с N цели числа. Да се намери K-тия по големина елемент в редицата.  */

/*
int main(void)
{
    int N,i,j,tmp,k;
  printf("n = ");
  scanf("%d", &N);

  printf("k = ");
  scanf("%d", &k);

  int a[N];

  for(i=0;i<N;i++) {printf("a[%d] = ", i);
  scanf("%d", &a[i]);}

    for(i=0;i<N-1;i++)
        for(j=0;j<N-i-1;j++)
            if(a[j] < a[j+1]) {tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp;}


printf("%d ", a[k]);
    return 0;
}
*/


// Задача 6

/* За дадена редица от числа да се намери и отпечата
най-дългата (монотонно) нарастваща (или намаляваща) под редица */

/*
int main(void)
{
    int N, i, k, maxcount=0, count1=0,count2=0; // 1 - разстяща, 2 - намаляваща
    scanf("%d", &N);
    int a[N];
    for(i=0;i<N;i++) scanf("%d",&a[i]);

   // int a[] = {4,5,7,7,8,9,6,5,4,3,8,3,9,2,1};
    N = sizeof(a) / sizeof(a[0]);


    for(i=1;i<N;i++)
    {
        // 1 - разстяща
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

        // 2 - намаляваща
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
*/


/* Упражнение 5 */

// Задача 1

/* Даден е двумерен масив NxM запълнен с цели числа.
Проверете дали всеки ред съдържа числа, подредени в нарастващ ред,
а всяка колона съдържа числа подредени в намаляващ ред. */

/*
int main(void)
{
    int N,M,i,j;
    int desO = 1, asO = 1; // descending and ascending order
    printf("N = ");
    scanf("%d", &N); // редове
    printf("M = ");
    scanf("%d", &M); // колони

    // Defining the array
    int ar[N][M];

    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
        {
            scanf("%d", &ar[i][j]);
        }


    // Printing the array
    for(i=0; i<N; i++)
    {
        puts("");
        for(j=0; j<M; j++)
        {
            printf("%d ", ar[i][j]);
        }
    }

    // Checking for ascending and descending order

    // Ascending
    for(i=0; i<N; i++)
    {
        for(j=1; j<M; j++)
        {
            if(ar[i][j] < ar[i][j-1]) {asO = 0; break;}
        }
        if(!asO) break;
    }

    // Descending
        for(i=0; i<M; i++)
        {
            for(j=1; j<N; j++)
            {
                if(ar[j][i] > ar[j-1][i]) {desO = 0; break;}
            }
            if(!desO) break;
        }

        puts("");
    if(asO) puts("The rows are in ascending order.");
        else puts("The rows are not in ascending order");
    if(desO) puts("The columns are in descending order.");
        else puts("The columns are not in descending order.");
    return 0;
}
*/

// Задача 2

/* Даден е масив NxM запълнен с цели числа.
Намерете числото, което има околни на него сбора,
 на които е най-голям. (околно е всяко число което се намира до,
над, под или по диагонал на текущото на отстояние не повече от 1 поле). */

/*
int main(void)
{
    int i,j,N,M;
    int maxsum = NULL, sum=0, maxI, maxJ;

     printf("N = ");
    scanf("%d", &N);
    printf("M = ");
    scanf("%d", &M);

     // Defining the array
    int a[N][M];

    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
        {
            scanf("%d", &a[i][j]);
        }


    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
        {
            // горен ред
            if(i>0){
                if(j>0) sum += a[i-1][j-1];
                sum += a[i-1][j];
                if(j<M-1) sum += a[i-1][j+1];
            }

            // среден ред
            if(j>0) sum += a[i][j-1];
            if(j<M-1) sum += a[i][j+1];

            // долен ред
            if(i<N-1){
                if(j>0) sum += a[i+1][j-1];
                sum += a[i+1][j];
                if(j<M-1) sum += a[i+1][j+1];
            }

             // нулираме сумата и проверяваме дали е по-голяма от максимума
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
*/


// Задача 3

/* Дадена е матрица NxM запълнена с цели числа.
Разменете редовете с най-голям и най-малък елемент. */

/*
int main(void)
{
     int i,j,N,M;
    int max, min, maxI, minI;

     printf("N = ");
    scanf("%d", &N);
    printf("M = ");
    scanf("%d", &M);

     // Defining the array
    int a[N][M];

    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
        {
            scanf("%d", &a[i][j]);
        }

        max = min = a[0][0];
        maxI = minI = 0;
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
    {
        if(a[i][j] > max) {max = a[i][j]; maxI = i;}
        if(a[i][j] < min) {min = a[i][j]; minI = i;}
    }

    int tmp;
    for(j=0; j<M; j++)
    {
        tmp = a[maxI][j];
        a[maxI][j] = a[minI][j];
        a[minI][j] = tmp;
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
            printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}
*/


// Задача 4

/*  В училището на Ели има 1 ≤ N ≤ 100,000 човека.
    Някои от тях се познават с други, като Ели знае,
    че съществуват 1 ≤ M ≤ 1,000,000 такива приятелства.
    Тя иска да напише програма, която бързо отговаря кои
    са приятелите на даден човек. Ако хората се подават с
    номера като цяло число, както и приятелите им изведете
    при поискан човек колко приятели има.
    (ако 1 е приятел с 3 то и 3 е приятел с 1). */

    /*
    int main(void)
    {
        int N,M;
        int i,j;
        int p1,p2;
        int tmp;

        printf("M : ");
        scanf("%d",&N);
        printf("N : ");
        scanf("%d",&M);

        // нулиране на масива
        int a[N][M];
        for(i=0; i<N; i++)
            for(j=0; j<M; j++)
                a[i][j] = 0;


        // сприятеляване
        for(i=0; i<M; i++)
        {
            do{
            puts("link a friends:");
            scanf("%d", &p1);
            scanf("%d", &p2);} while(p1>N || p2>N);

            tmp = 0;
            while(a[p1-1][tmp]) tmp++;
            a[p1-1][tmp] = p2;
            tmp = 0;
            while(a[p2-1][tmp]) tmp++;
            a[p2-1][tmp] = p1;
        }

        // извеждане на ненулеви елементи от масива

        printf("\nList of friends:\n");
        for(i=0;i<N; i++){
                printf("%d : ", i+1);
            for(j=0;a[i][j] && j<M; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }

        / извеждане на приятелите
        printf("\nWhich person you want?\n");
        scanf("%d",&tmp);
        for(i=0; a[tmp-1][i]; i++) printf("%d ", a[tmp-1][i]);
    return 0;
    }
*/

/* Задача 4.2

/*  В училището на Ели има 1 ≤ N ≤ 100,000 човека.
    Някои от тях се познават с други, като Ели знае,
    че съществуват 1 ≤ M ≤ 1,000,000 такива приятелства.
    Тя иска да напише програма, която бързо отговаря кои
    са приятелите на даден човек. Ако хората се подават с
    номера като цяло число, както и приятелите им изведете
    при поискан човек колко приятели има.
    (ако 1 е приятел с 3 то и 3 е приятел с 1). */

    /*
     void mkFriend(int * pr, int fr ,int count);

    int main(void)
    {
        int N, M;
        int i,j;
        int pr1, pr2;


        do{
            printf("N = "); // хора
            scanf("%d", &N);
            } while(N > 100000 || N < 1);

        do{
            printf("M = "); // приятелски връзки
            scanf("%d", &M);
            } while(N > 100000000 || N < 1);

        int size[N];
        for(i=0;i<N;i++)
            size[i] = 1;

        // масив от N елемента
        int ** pr;
        pr = (int **)malloc(N*sizeof(int *));
        if(pr == NULL) exit(1);

        // вграден масив
        for(i=0; i<N; i++)
        {
            pr[i] = (int *)calloc(1,sizeof(int));
            if(pr[i] == NULL) exit(1);
        }


        // създаване на приятелства

        puts("Write the friend links:");
        for(i=0; i<M; i++){
            do{
            scanf("%d", &pr1);
            scanf("%d", &pr2);}
                    while(pr1>N || pr2>N);

           mkFriend(&pr[pr1-1], pr2, size[pr1-1]);
           mkFriend(&pr[pr2-1], pr1, size[pr2-1]);
        }

        // принтиране на връзките
        for(i=0; i<N; i++)
        {
            printf("\n");
            printf("%d: ", i+1 );
            for(j=0; j < size[i]; j++)
            {
                printf("%d ", pr[i][j]);
            }
        }

        return 0;
    }


    void mkFriend(int * pr, int fr ,int count)
    {
        // ако няма връзка с друг не се променя размера

        if(pr[0]){
            pr = (int *)realloc(pr, (++count)*sizeof(int));
            if(pr == NULL) exit(1);
           }

        pr[count-1] = fr;
    }
*/

// Задача 5
// #include<stdio.h>
// #include<stdlib.h>
// include<time.h>

// #define N 5

/* Наум пише софтуер за малки деца, който има следните команди:

1: add(x) - добавяне на елемент Х към съществуващите до момента

2: delete(x) – изтрива всички срещания на елемента Х

3: smallest(x)  принтира Х тото най-малко число от наличните

Помогнете на Наум да напише своя софтуер, ако знаете, че Х е цяло число. */

/*
int count = N;
int *arr;

void MyReall(int);
void fillAr();
void MyPrint();
void add(int);
void del(int);
void smallest(int);

int main(void)
{
    arr = (int *)malloc(N*sizeof(int));
    if(arr == NULL) exit(1);
    fillAr();
    MyPrint();

    int mod,x;

    do{
        printf("\nWrite a mode: (1:add(), 2:del(), 3:smallest(), 4:MyPrint() or 0: exit())\n");
        scanf("%d", &mod);
        if(!mod) exit(1);

        switch(mod)
        {
        case 1:
            printf("adding x = ");
            scanf("%d",&x);
            add(x);
            break;
        case 2:
            printf("deleting all Xs: ");
            scanf("%d",&x);
            del(x);
            break;
        case 3:
            printf("Choose n's smallest number: ");
            scanf("%d",&x);
            smallest(x);
            break;
        case 4:
            do{
            printf("x = ");
            scanf("%d", &x);} while(x >= count);
            MyPrint();
            break;
        default:
            printf("You wrote a wrong number... Try again.");
        }
    } while(1);

    return 0;
}

// промяна на броя на елементите
void MyReall(int n)
{
     arr = (int *)realloc(arr, n*sizeof(int));
    if(arr == NULL) exit(1);
}

// запълване на масива със случайни стойности
void fillAr()
{
    srand(time(NULL));
    for(int i=0; i<count; i++) arr[i] = rand()%10;
}

// принтиране на масива
void MyPrint()
{
    for(int i=0; i<count; i++) printf("%d ", arr[i]);
    printf("\n");
}

// добавяне на един елемент
void add(int x)
{
    MyReall(++count);
    arr[count-1] = x;
}

// премахване на всички елементи равни на x
void del(int x)
{
    int tmpCount = 0;

    for(int i=0; i<count; i++)
    {
        if(arr[i] == x){
            tmpCount++;
            continue;
        }
        arr[i-tmpCount] = arr[i];
    }

    count -= tmpCount;
    MyReall(count);
}

void smallest(int x)
{
    int a[count];
    int tmp, k=0;

    // копиране на масива в друг
    a[0] = arr[0];
    for(int i=1; i<count; i++) a[i] = arr[i];

    // сортиране във възходящ ред
    for(int i=0; i<count; i++)
        for(int j=0; j<count-i-1; j++)
            if(a[j] > a[j+1]){
            tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
            }

    // премахва повтарящите елементи
    for(int i=1; i<count; i++)
    {
        if(a[i] == a[i-1])
        {
            k++;
            continue;
        }
        a[i-k] = a[i];
    }

    printf("%d'th smallest number is: %d", x, a[x-1]);
}
*/

/* Упражнение 6 */

// Задача 1

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

 /*
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
*/

/* Стаско е програмист и има хоби да прави сладкарски изделия. Помогнете му да напише програма,
    с която да менажира произведените сладка и техните доставки. За целта трябва да създадете структура
    за продукт, която да описва име на продукта, цена и уникален номер. Създайте и структура за поръчки,
    която да описва адрес на клиент и номер на продукт.

    От стандартния вход постъпват множество продукти и поръчки.
    Когато Стаско прави сладко той го добавя в списък на създадените сладка,
    а когато се пуска поръчка тя се изпълнява при наличие на продукт, иначе чака до създаването му.

За входни данни ще получавате две команди:

Product

<име на продукт>

<цена>

<номер на продукта>

Тази команда създава нов продукт и го добавя в списъка с продукти.
Ако има поръчка за този продукт то поръчката се изпълнява незабавно и се маха от чакащите за изпълнение.

Order

<адрес>

<номер на продукт>

Ако има наличен вече произведен продукт се изпълнява поръчката, в противен случай чака за създаване на продукта.

При всяко изпълнение на поръчка изписвайте: Client <address> ordered <product name>

Програмата приключва работа при въвеждане на команда END  */


/*
typedef struct TItem
{
    char name[20];
    double price;
    int ID;
} Item;

typedef struct TOrder
{
    char adress[50];
    int IDP;  // ID of the product
} Order;

#define SEP printf("\n################\n")
#define NL printf("\n")


Item mkItem();
Order mkOneOrder();
int rmProduct(int IDP, Item products[], int *countPr);
int rmOrder(int IDP, Order order[], int *countOr);
Item *mkProduct(Item products[], Order orders[], int *countPr, int *countOr);
Order *mkOrder(Item products[], Order orders[], int *countPr, int *countOr);
void Print(Item products[], Order orders[], int countPr, int countOr);


int main(void)
{
    // Make a choice for product and order
    char choice[8];
    int countPr = 0, countOr = 0;
    Item * products;
    Order * orders;


// Make a list of products and orders
    products = NULL;
    orders = NULL;

    while(1)
    {
        printf("Choose Product, Order, Print or END:  ");
        scanf(" %[^\n]s", &choice);

        // End the program
        if(!strcmp(choice, "END")) break;

        // Check the choice
        if(!strcmp(choice, "Product")) products = mkProduct(products, orders, &countPr, &countOr);
        if(!strcmp(choice, "Order")) orders = mkOrder(products, orders, &countPr, &countOr);

        // Print the product and order list
        if(!strcmp(choice, "Print")) Print(products, orders, countPr, countOr);

    }

    free(products);
    free(orders);
    return 0;
}


void Print(Item products[], Order orders[], int countPr, int countOr)
{
    int i;

    SEP;

    // Products
    for(i=0; i<countPr; i++)
    {
        printf("\nProduct #%d\n", i+1);
        printf("Name: %s\n", products[i].name);
        printf("Price: %g\n", products[i].price);
        printf("ID: %d\n", products[i].ID);
    }


    if(countOr) SEP;


    //Orders
    for(i=0; i<countOr; i++)
    {
        printf("\nOrders #%d\n", i+1);
        printf("Address: %s\n", orders[i].adress);
        printf("IDP: %d\n", orders[i].IDP);
    }


    SEP;
    NL;

}

// Product
Item *mkProduct(Item products[], Order orders[], int *countPr, int *countOr)
{
    int i,j;
    Item item;

    item = mkItem();

    /*
    // Check if it is in order
    for(i=0; i< *countOr; i++)
        if(item.ID == orders[i].IDP) {
            // remove the order
            for(j=i+1; j< *countOr; j++)
                orders[j-1] = orders[j];
            orders = (Order *)realloc(orders, --(*countOr) * sizeof(Order));

        return products;} */

    int isInOrder = rmOrder(item.ID, orders, countOr); // countOr is the pointer
    if(isInOrder) return products;

    // append the item to the item list
    products = (Item *)realloc(products, ++(*countPr) * sizeof(Item));
    if(products == NULL) exit(1);
    products[*countPr - 1] = item;

    return products;
}

// make an item
Item mkItem()
{
    Item item;

    printf("\nMake a Product:\n");
    printf("Item: ");
    scanf(" %[^\n]s", &item.name);
    printf("Price: ");
    scanf("%lf", &item.price);
    printf("ID: ");
    scanf("%d", &item.ID);
    NL;

    return item;
}

// Order
Order *mkOrder(Item products[], Order orders[], int *countPr, int *countOr)
{
    int i,j;

    Order order;
    order = mkOneOrder();

    // remove item from item list IF there is available
    int isRmv = rmProduct(order.IDP, products, countPr); // countPr is the pointer
    if(isRmv) return orders;

   // append order to the order list IF there is no available item
   orders = (Order *)realloc(orders, ++(*countOr) * sizeof(Order));
   if(orders == NULL) exit(1);
   orders[*countOr - 1] = order;

   return orders;
}

int rmProduct(int IDP, Item products[], int *countPr)
{
    int i, j;

     for(i=0; i<*countPr; i++)
        // remove item from item list IF there is available
        if(IDP == products[i].ID) {
            for(j=i+1; j<*countPr; j++)
                products[j-1] = products[j];
            if(!(*countPr - 1)) {(*countPr)--; return 1;}
            products = (Item *)realloc(products, --(*countPr) * sizeof(Item));
            if(products == NULL) exit(1);
            return 1;
       }

       return 0;
}

int rmOrder(int IDP, Order orders[], int *countOr)
{
    int i, j;

     for(i=0; i<*countOr; i++)
        // remove order from order list IF there is available
        if(IDP == orders[i].IDP) {
            for(j=i+1; j<*countOr; j++)
                orders[j-1] = orders[j];
            if(!(*countOr - 1)) {(*countOr)--; return 1;}
            orders = (Order *)realloc(orders, --(*countOr) * sizeof(Order));
           if(orders == NULL && *countOr) exit(1);
            return 1;
       }

       return 0;
}

Order mkOneOrder()
{
    Order order;

    printf("\nOrdering:\n");
    printf("Adress: ");
    scanf(" %[^\n]s", &order.adress);
    printf("ID: ");
    scanf("%d", &order.IDP);
    NL;

    return order;
}
*/
