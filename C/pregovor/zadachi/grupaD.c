#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
1. �������� ��������� ������, ��������� ���������� �� ����. �������� �� ������ � ������������.
�������� ������� �� ������ ��� ������ ����������. �������� �������, ����� ���� ���������� �� ������� ��
������� ���� � �� ������ � �������. ����� �� ����� � ��������� �� ���������.

2. �������� ������� diffPriceLaptop, ����� ������ ��������� ����� ������� � ���������� � ������� � ��������� ����
� � �����. �������� �������, ����� ����� ���� �� ��������� � ����, ��-������ �� 2.5*diff
(diff � ��������� ����� ������������ � ����������� ���� � ������� ���� ���������� ���������� ������� diffPriceLaptop)
� ������������ �������� ���� ���������.

3. ����������� �������, ����� ������� ������� �� ������� �� ��������, ���� ���������, �������� �� ������.
�������� ������� � ������� ���� ����������� �������.

4. �������� �������, ����� ������� ������ �������, ����� ���� �������� ���o ��������� �������� �� ������ � ����.
*/


typedef struct{
    float price;
    float inch;
    char manufacture[15];
} Laptop;

#define N 4

// Function declaration
Laptop *Reading(char name[], int sizeOfList);
void Writing(char name[], Laptop *list, int sizeOfList);
void PrintList(Laptop *list, int size);
void primaryData();
float maxPrice();
float minPrice();
float diffPriceLaptop();
int countBiggerDiff();
int mkListByScreen(float screenSize);
void rmvLaptops(float screenSize, float price);


// Global variables
Laptop *laptops = NULL;
Laptop *screenLaptops = NULL;
int size = N;

int main(void)
{
    int sizeOfScreenLaptops;

    //primaryData();
    //Writing("laptops", laptops, size);
    laptops = Reading("laptops", size);
    PrintList(laptops,size);
    printf("Count of laptops' price bigger than diff: %d\n", countBiggerDiff());

    sizeOfScreenLaptops = mkListByScreen(15);
    screenLaptops = Reading("newLaptops", sizeOfScreenLaptops);
    printf("\nLaptops with screen size 15:\n");
    PrintList(screenLaptops, sizeOfScreenLaptops);

    rmvLaptops(15, 465);
    printf("\nAfter removing:\n");
    PrintList(laptops,size);

    if(laptops != NULL) free(laptops);
    return 0;
}

// Writing function for testing
void Writing(char name[], Laptop *list, int sizeOfList)
{
    FILE *fp = fopen(name,"wb");
    if(fp == NULL) exit(1);

    fwrite(list,sizeof(Laptop),sizeOfList,fp);
    free(list);

    fclose(fp);
}

// Set testing data
void primaryData()
{
    laptops = (Laptop *)malloc(N*sizeof(Laptop));
    if(laptops == NULL) exit(1);

    int i;
    for(i=0; i<N; i++)
    {
        laptops[i].price = 15 * (i+1) * (i+1) + 300 * (i+1) - 250*(i*1.3);
        laptops[i].inch = 3*(i+2)*(i+1) - 5*i;
        strcpy(laptops[i].manufacture, "Lenovo");
    }

    laptops[1].inch = 15;
    laptops[2].inch = 15;
}

// Reading data
Laptop *Reading(char name[], int sizeOfList)
{
    Laptop *list = (Laptop *)malloc(sizeOfList*sizeof(Laptop));
    if(list == NULL) exit(1);

    FILE *fp = fopen(name,"rb");
    if(fp == NULL) exit(1);

    fread(list,sizeof(Laptop),sizeOfList,fp);

    fclose(fp);

    return list;
}

// Printing the list
void PrintList(Laptop *list, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("price : %g\n", list[i].price);
        printf("inches : %g\n", list[i].inch);
        printf("manufacture : %s\n\n", list[i].manufacture);
    }
}

// Find the difference between minimum price and maximum price of the list of laptops
float diffPriceLaptop()
{
    float min = minPrice();
    float max = maxPrice();

    return max - min;
}

// Find the minimum price from the list of laptops
float minPrice()
{
    float min = laptops[0].price;
    int i;
    for(i=1; i<size; i++)
        if(laptops[i].price < min) min = laptops[i].price;

    return min;
}

// Find the maximum price from the list of laptops
float maxPrice()
{
    float max = laptops[0].price;
    int i;
    for(i=1; i<size; i++)
        if(laptops[i].price > max) max = laptops[i].price;

    return max;
}

// Count of laptops' price bigger than diff
int countBiggerDiff()
{
    int count = 0;
    int i;
    float diff = diffPriceLaptop();
    for(i=0; i<size; i++)
        if(laptops[i].price > 2.5 * diff) count++;

    return count;
}

// Make a new list by given size of the screen
int mkListByScreen(float screenSize)
{
    Laptop *newList = NULL;
    int nSize = 0;
    for(int i=0; i<size; i++)
        if(laptops[i].inch == screenSize) {
            newList = (Laptop *)realloc(newList, ++nSize*sizeof(Laptop));
            if(newList == NULL) exit(1);

            newList[nSize-1] = laptops[i];
        }

    Writing("newLaptops", newList, nSize);
    free(newList);
    return nSize;
}


// Remove every laptop by screen size or price
void rmvLaptops(float screenSize, float price)
{
    int i,j;
    for(i=0; i<size; i++)
    if(laptops[i].inch == screenSize || laptops[i].price == price){
            for(j=i+1; j<size; j++)
                laptops[j-1] = laptops[j];
            laptops = (Laptop *)realloc(laptops, --size*sizeof(Laptop));
            if(laptops == NULL) exit(1);
            i--; // if you have two laptops with the same size or price
    }
}
