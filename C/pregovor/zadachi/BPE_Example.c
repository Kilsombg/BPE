#include<stdio.h>

/*
������ 1.
������� ���������, ����� �� ��������� ���������� �� ���������� � �������. ������������� ���������� �� ����� ���� ������� �:
�	��� �� ������� (��� ����� 1 � 30 �������)
�	ID (���) �� ������� (���� �����)
�	���� �� ������� (��� � ������ ����.��.��)
�	���� �� ������� (������ �����)

�������� �����, � ����� �� ����������� ����������. �������� ������� ���� � ��� �in.bin�
�� ���� ����������� ���������, �������� �������, ����� �� ������ ��� ������� ����� � ������,
���� � � �������� ����. �� ���������� �� �������� �������� �� ������� ��������� ��� �����.

������ 2.
�������� �������, ����� ������ ����� �� �������� � ����, ���� ����� ����� ����� �� ��������,
����� ���� � ��-������ �� ����������. �������� ����� ������ �� �� �������� �� ��������� �� �������� �������.

������ 3.
�������� �������, ����� ������� ������� �� �������� �� ���� ���������� � �������� ������� ���� �in.bin�,
���� ����� �� ������� � �������� ���� �outTxt� � �������� �������������� �� ����� ���� ����� � ���������.
*/

typedef struct{
    char name[30];
    int ID;
    char expire[11];
    float price;
} product;

// Function declaration
void addProduct(char name[], int id, char expreDate[], float price);
void printList(product* list, int sizeList);
void readData();
product* listBiggerPrice(product* list, int price);
void writeToTxt();
void readTxt();

// Global variables
const char* inFileName = "in.bin";
const char* outFileName = "outTxt.txt";
product* Store = NULL;
product* bigList= NULL;
int size = 0;
int sizeBigList = 0;

int main(void)
{
    //addProduct("apple", 101, "2024.03.30", 1.2);
    //addProduct("banana", 102, "2025.07.31", 0.8);

    //readData();
    //printList(Store, size);

   // bigList = listBiggerPrice(Store, 1);
   // printList(bigList, sizeBigList);

  // writeToTxt();
   readTxt();
   printList(Store, size);

    return 0;
}

// Add product to the Store
void addProduct(char name[], int id, char expreDate[], float price)
{
    FILE* fp = fopen(inFileName, "ab");
    if(fp == NULL) exit(1);

    Store = (product *)realloc(Store, ++size*sizeof(product));
    if(Store == NULL) exit(1);

    strcpy(Store[size-1].name, name);
    strcpy(Store[size-1].expire, expreDate);
    Store[size-1].ID = id;
    Store[size-1].price = price;

    if(fwrite(&Store[size-1], sizeof(product), 1, fp) != 1) printf("writing error\n");

    fclose(fp);
}

// Read data
void readData()
{
    FILE* fp = fopen(inFileName, "rb");
    if(fp == NULL) exit(1);

    product item;
    size = 0;

    while(1)
    {
        fread(&item, sizeof(product), 1, fp);
        if(feof(fp)) break;

        Store = (product *)realloc(Store, ++size*sizeof(product));
        if(Store == NULL) exit(1);
        Store[size-1] = item;
    }

    fclose(fp);
}

// printList
void printList(product* list, int sizeList)
{
    int i;
    for(i=0; i<sizeList; i++)
    {
        printf("name: %s\n", list[i].name);
        printf("ID: %d\n", list[i].ID);
        printf("expire: %s\n", list[i].expire);
        printf("price: %g\n\n", list[i].price);
    }
}

// returns array of product with bigger price
product* listBiggerPrice(product* list, int price)
{
    product* newList = NULL;
    sizeBigList = 0;

    int i;
    for(i=0; i<size; i++)
        if(list[i].price > price)
    {
        newList = (product *)realloc(newList, ++sizeBigList*sizeof(product));
        if(newList == NULL) exit(1);

        newList[sizeBigList-1] = list[i];
    }

    return newList;
}


// write data into txt file
void writeToTxt()
{
    readData();

    FILE* fp = fopen(outFileName, "w");
    if(fp == NULL) exit(1);

    int i;
    for(i=0; i<size; i++)
    {
        fprintf(fp, " %s %d %s %f", Store[i].name, Store[i].ID, Store[i].expire, Store[i].price);
    }

    fclose(fp);
}


// Read from txt file data
void readTxt()
{
    FILE* fp = fopen(outFileName, "r");
    if(fp == NULL) exit(1);

    size = 0;

    while(1)
    {
        if(feof(fp)) break;

        Store = (product *)realloc(Store, ++size*sizeof(product));
        if(Store == NULL) exit(1);

        fscanf(fp, " %s %d %s %f", Store[size-1].name, &Store[size-1].ID, Store[size-1].expire, &Store[size-1].price);
    }
    fclose(fp);
}
