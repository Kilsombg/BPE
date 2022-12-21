#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 5

/* Наум пише софтуер за малки деца, който има следните команди:

1: add(x) - добавяне на елемент Х към съществуващите до момента

2: delete(x) – изтрива всички срещания на елемента Х

3: smallest(x)  принтира Х тото най-малко число от наличните

Помогнете на Наум да напише своя софтуер, ако знаете, че Х е цяло число. */


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

/* промяна на броя на елементите */
void MyReall(int n)
{
     arr = (int *)realloc(arr, n*sizeof(int));
    if(arr == NULL) exit(1);
}

/* запълване на масива със случайни стойности */
void fillAr()
{
    srand(time(NULL));
    for(int i=0; i<count; i++) arr[i] = rand()%10;
}

/* принтиране на масива */
void MyPrint()
{
    for(int i=0; i<count; i++) printf("%d ", arr[i]);
    printf("\n");
}

/* добавяне на един елемент */
void add(int x)
{
    MyReall(++count);
    arr[count-1] = x;
}

/* премахване на всички елементи равни на x */
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

    /* копиране на масива в друг */
    a[0] = arr[0];
    for(int i=1; i<count; i++) a[i] = arr[i];

    /* сортиране във възходящ ред */
    for(int i=0; i<count; i++)
        for(int j=0; j<count-i-1; j++)
            if(a[j] > a[j+1]){
            tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
            }

    /* премахва повтарящите елементи */
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
