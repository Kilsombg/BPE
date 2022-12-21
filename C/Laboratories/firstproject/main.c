/* ����������� 8 */

/* ��������� ������ */

/*  ������� �������:
void * malloc (size.t bytes)   // ������� ��������� ������������ � �������� [size.t bytes] �������
void * calloc(size.t elements, size.t bytes-per.element) // ������� ��������� ����� ���� ������� � ���������� ( ������ �� )
void * realloc(void * address, size.t new-size) // ������� ������� �� ���� ���������� ��������� �����
void free(void * array) // ����������� ������ �� �������


// ��������� : ��������� realloc() ������� ������� �� ������ ����� ���� ��������. ��� �� ���� ������ ��-����� �� �������� ������
�� ������, �� ����������� �������� �� ����������, ����� ���� �� �� �������� �� ����� �������� �� ����� ��������� �����. ��� ��
���� ������ ��-����� �� �������� ������ ��� ��� �����: ��� ��� ���������� �������� ������ ���� ������ �� ��������� ������� ��
�������� �����, �������������� �������� �� �������� �� ���. ��� ���� ���������� �������� ������ �� ������� ��� ����� �� ������,
������� �� ���������� �� ���������� ����� � �� ������� ����� �� ���������� ��������, ���� realloc() �� ������ ����������, ��
����� ���� �������� ������ ( ������� ��������� �� ���������� ���������� �� �������). ����������� ������� �� ��������� �����, ��
����� � ��� ���������� �����.

��������� malloc() �� �������� ��������� �� �������.

��������� calloc() �������� ��������� �� �������.


������ 1:

int *p;
// ����������� �� ��������� �����
p = (int *)malloc(4*sizeof(int)); || p = (int *)calloc(4,sizeof(int));

// ��������� �� ���������� �� ������
for(int i=0; i<4; i++)
{
    p[i] = i+1; <=> *(p + i) = i + 1;
}

// ��������� �� ���������� �� ������
p = (int *)realloc(p, 10*sizeof(int));

// �������� ���� ��������� ���� ��� ������� �����
if(p=NULL) exit(1);


������� 2:

int count = 7, n;
int *arr;
arr = (int *)malloc(count *sizeof(int));
for(n=0;n<count;n++)
{
    arr[n] = n;
}

// ��������� ����������� �� arr
int * narr;
narr = arr;

// ����������� ������� �� arr ��� ������������ �� realloc
arr = (int *) malloc(++count * sizeof(int));
for(n=0;n<count-1;n++)
    {
        arr[n] = narr[n];
    }
arr[count-1] = count;

// ������������� ����� �����, ������ ��� ���� �� �� � �����
free(naar);

// ��������� �� �������
naar = arr;
int x = 3;

// ����������� �� ���������� ���� ���� �������, ����� ������ �� ���������, ������
for(n=x; n<count; n++)
{
    narr[n-1] = narr[n];
}

// ��������� ����� � ��-����� ������ � ��������� ������ ����������� � ������
arr = (int *) malloc(--count * sizeof(int));
for(n=0;n<count;n++)
{
    arr[n] = narr[n];
}

free(narr);




������ 1:
�������� ��������, � ����� �� ������ ����� �� ��������� ����� � N �� ���� ��������, ���� N �� ������� �� �����������.
��������� ������ � �������� �� ������������. ���������� ������, ���� ����� ��������������� ���� ������� �� ������� ��
������������, ����������� realloc(). ��� ������� � ��-����� �� N �� �������� �������������� �������� � ������ �� �������
����� �����.


������ 2:
�������� ��������, � ����� �� ������ ����� �� �������� ��������� ����� �� ���� �����, ������� �� ��� ���������, ���� �����
�� ������� �������� � ���������� ������������ ����.

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
