#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 5

/* ���� ���� ������� �� ����� ����, ����� ��� �������� �������:

1: add(x) - �������� �� ������� � ��� �������������� �� �������

2: delete(x) � ������� ������ �������� �� �������� �

3: smallest(x)  �������� � ���� ���-����� ����� �� ���������

��������� �� ���� �� ������ ���� �������, ��� ������, �� � � ���� �����. */


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

/* ������� �� ���� �� ���������� */
void MyReall(int n)
{
     arr = (int *)realloc(arr, n*sizeof(int));
    if(arr == NULL) exit(1);
}

/* ��������� �� ������ ��� �������� ��������� */
void fillAr()
{
    srand(time(NULL));
    for(int i=0; i<count; i++) arr[i] = rand()%10;
}

/* ���������� �� ������ */
void MyPrint()
{
    for(int i=0; i<count; i++) printf("%d ", arr[i]);
    printf("\n");
}

/* �������� �� ���� ������� */
void add(int x)
{
    MyReall(++count);
    arr[count-1] = x;
}

/* ���������� �� ������ �������� ����� �� x */
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

    /* �������� �� ������ � ���� */
    a[0] = arr[0];
    for(int i=1; i<count; i++) a[i] = arr[i];

    /* ��������� ��� �������� ��� */
    for(int i=0; i<count; i++)
        for(int j=0; j<count-i-1; j++)
            if(a[j] > a[j+1]){
            tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
            }

    /* �������� ����������� �������� */
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
