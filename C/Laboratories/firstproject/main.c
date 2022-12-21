/* Лабораторно 8 */

/* Динамични масиви */

/*  Основни функции:
void * malloc (size.t bytes)   // създава динамично пространство с големина [size.t bytes] байтове
void * calloc(size.t elements, size.t bytes-per.element) // създава динамичен масив като създава и елементите ( нулира ги )
void * realloc(void * address, size.t new-size) // променя размера на вече създадения динамичен масив
void free(void * array) // освобождава масива от паметта


// ЗАБЕЛЕЖКА : фунцкията realloc() променя размера на масива даден като аргумент. Ако се даде размер по-малък от сегашния размер
на масива, тя освобождава адресите на елементите, които вече не би следвало да бъдат елементи на новия динамичен масив. Ако се
даде размер по-голям от сегашния размер има две опции: ако има достатъчно свободни адреси след адреса на последния елемент от
сегащния масив, допълнителните елементи се записват на тях. Ако няма достатъчно свободни адреси се формира нов адрес на масива,
копират се елементите от динамичния масив и се запазва памет за останалите елементи, като realloc() не нулира елементите, за
които няма стойност масива ( остават стойности от предишното използване на паметта). Освобождава паметта на предишния адрес, на
който е бил динамичния масив.

функцията malloc() не занулява елемнтите от паметта.

функцията calloc() занулява елемнтите от паметта.


Пример 1:

int *p;
// деклариране на динамичен масив
p = (int *)malloc(4*sizeof(int)); || p = (int *)calloc(4,sizeof(int));

// достигане до елементите на масива
for(int i=0; i<4; i++)
{
    p[i] = i+1; <=> *(p + i) = i + 1;
}

// променяне на елементите на масива
p = (int *)realloc(p, 10*sizeof(int));

// проверка дали указателя сочи към някакъв адрес
if(p=NULL) exit(1);


Прирмер 2:

int count = 7, n;
int *arr;
arr = (int *)malloc(count *sizeof(int));
for(n=0;n<count;n++)
{
    arr[n] = n;
}

// запазваме стойностите на arr
int * narr;
narr = arr;

// увеличаваме размера на arr без използването на realloc
arr = (int *) malloc(++count * sizeof(int));
for(n=0;n<count-1;n++)
    {
        arr[n] = narr[n];
    }
arr[count-1] = count;

// освобождаваме новия масив, защото той вече не ни е нужен
free(naar);

// изтриване на елемент
naar = arr;
int x = 3;

// преместване на елементите след този елемент, който искаме да премахнем, наляво
for(n=x; n<count; n++)
{
    narr[n-1] = narr[n];
}

// създаваме масив с по-малък размер и запазваме новите стойностите в масива
arr = (int *) malloc(--count * sizeof(int));
for(n=0;n<count;n++)
{
    arr[n] = narr[n];
}

free(narr);




Задача 1:
Напишете програма, в която се заделя памет за динамичен масив с N на брой елемента, като N се въвежда от потребителя.
Запълваме масива с елементи от клавиатурата. Принтираме масива, след което преоразмеряваме като размера се въвежда от
клавиатурата, използвайте realloc(). Ако размера е по-голям от N се въвеждат допълнителните елементи и накрая се извежда
новия масив.


Задача 2:
Напишете програма, в която се заделя памет за двумерен динамичен масив от цели числа, запълва се със стойности, след което
се сумират колоните и принтираме максималната сума.

*/



/*

// dynamic arrays

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i;
    int * p1;

    p1 = (int *)malloc(0*sizeof(int));


    p1 = (int *)realloc(p1,10*sizeof(int));
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;

    for(i=0; i<10; i++)
    {
        printf("%d ", p1[i]);
    }

    return 0;
}
*/


/* ############################################# */

/*
// put pointer as an argument

void change(int *a);
void change2(int *a);

int main(void)
{
    int a = 3;

    change(&a);
    printf("%d", a);
    return 0;
}

void change(int *b)
{
    *b = 4;
    change2(b);   // b is pointer to a
}

void change2(int *c)
{
    *c = 5;
}
*/


/* ################################# */


/*
// pass an array as parameter

int main(void)
{
    int n = 20;
    int a[n];
    putV(a,n);

    int * b;
    b = malloc(n*sizeof(int));
    putV(b,n);

   print(a,n);
   print(b,n);
    return 0;
}

void print(int arr[],int n)
{
     for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void putV(int a[],int n)
{
    int i;
    for(i=0; i<n; i++)
        a[i] = i+1;
}
*/

/* ############################################# */

/* struct array */
/* Correct */

struct Item
{
    int count;
};

struct Item mkItem();
struct Item * insertItem(struct Item *items, int *size);
void printItem(struct Item *items, int size);

int main(void)
{
    struct Item *items;
    int size = 0;
    items = insertItem(items, &size);
    printItem(items,size);
    items = insertItem(items, &size);
    printItem(items,size);

    free(items);
    return 0;
}

struct Item * insertItem(struct Item items[], int *size)
{
    struct Item item = mkItem();

    if(!(*size)) items = (struct Item *)malloc(++(*size) * sizeof(struct Item));
    else items = realloc(items, ++(*size) * sizeof(struct Item));

    items[*size - 1] = item;

    return items;
}

struct Item mkItem()
{
    struct Item item;
    printf("count: ");
    scanf("%d", &item.count);
    return item;
};

void printItem(struct Item *items, int size)
{
    int i;
    for(i=0; i<size;i++)
        printf("%d ", items[i].count);
}
