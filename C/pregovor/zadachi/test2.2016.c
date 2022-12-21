#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Трябва да опишете структура, която да съхранява информация за склад за Сладолед. В склада всеки запис се състои
от име на продукта(20 знака), тегло, което се съхранява в килограми, тип сладолед (комбинация от главни букви и цифра) и
цена на килограм.

Използвайте описаната структура, напишете функция за изчисляване на общата стойност на даден
сладолед(подаден като параметър) в склада. Функцията има следния прототип:
    double totalCost(LIST* head, char[]ch);

Напишете фунцкия която попълва списък с данни от файл стеково. Функцията има прототип:
    LIST* createStackList(LIST* head, FILE* fp);

Напишете как ще извикате функцията и какви променливи/параметри ще подадете.

Напишете функция, която записва във файл отделни елементи на списък. Номерата на елементите от списъка, които
трябва да се запишат във файла се подават като масив от целочислени стойности. Функцията има следния прототип.
    void writeningInFile(File* fp, LIST* head, int[] numbs);

Напишете функция, която записва данните от списък във файл в обратен ред. Функцията има следния прототип:
    void reverse(FILE* FP, LIST* head);
*/

typedef struct{
    char name[20];
    float weight;
    char type[10];
    double price;
} IceCream;

// Function declaration
double totalCost(IceCream* list, char name[]);
IceCream* createStackList(IceCream* list, FILE* fp);
void primaryData();
void Writing();
void PrintList(IceCream* list, int listSize);
IceCream* writingInFile(FILE* fp, IceCream* list, int numbers[]);
IceCream* readingInFile(int sizeList);

// Global variables
IceCream *List = NULL;
IceCream *newList = NULL;
int size = 0;
const char *fileName = "iceCream.bin";

int main(void)
{
    //primaryData();
   // Writing();
    //PrintList(List, size);

    FILE* fp = fopen(fileName,"rb");
    if(fp == NULL) exit(1);
    List = createStackList(List, fp);
    fclose(fp);

    PrintList(List,size);
    double vanilla = totalCost(List,"vanilla");
    printf("\ntotalCost: %g\n", vanilla);

    /*
    printf("\nWriting chosen elements:\n");
    fp = fopen(fileName,"wb");
    int indexList[] = {0,1,2,3};
    int sizeIndexList = sizeof(indexList) / sizeof(indexList[0]);
    newList = writingInFile(fp, List, indexList);
    PrintList(newList,sizeIndexList);
*/


    return 0;
}

// Writing data
void Writing()
{
    FILE* fp = fopen(fileName, "wb");
    if(fp == NULL) exit(1);

    fwrite(List, sizeof(IceCream), size, fp);

    fclose(fp);
}

// Primary data
void primaryData()
{
    size = 4;
    List = (IceCream *)malloc(size*sizeof(IceCream));
    if(List == NULL) exit(1);

    int i;
    for(i=0; i<size; i++)
    {
        List[i].weight = i+1;
        List[i].price = 0.5*(i+1);
        strcpy(List[i].name, "vanilla");
        strcpy(List[i].type, "VA1");
    }

    strcpy(List[2].name, "Choco");
    strcpy(List[2].type, "Ch2");

    strcpy(List[3].name, "Choco");
    strcpy(List[3].type, "Ch2");
}


// Print list
void PrintList(IceCream* list, int listSize)
{
    printf("\nPrint list:\n");

    int i;
    for(i=0; i<listSize; i++)
    {
        printf("name: %s\n", list[i].name);
        printf("weight: %g\n", list[i].weight);
        printf("type: %s\n", list[i].type);
        printf("price: %g\n\n", list[i].price);
    }
}

// Find total price of given icecream
double totalCost(IceCream* list, char name[])
{
    int i;

    for(i=0; i<size; i++)
    {
        if(!strcmp(list[i].name, name)) {
                return list[i].price * list[i].weight;
        }
    }

    printf("Product not found.\n");
    return -1;
}


// input product to the list like stack
IceCream* createStackList(IceCream* list, FILE* fp)
{
    int i;
    IceCream item;
    while(1)
    {
        fread(&item,sizeof(IceCream),1,fp);
        if(feof(fp)) break;

        list = (IceCream *)realloc(list, ++size*sizeof(IceCream));
        if(list == NULL) exit(1);

        for(i=size-1; i>0; i--)
            list[i] = list[i-1];
        list[0] = item;
    }
    return list;
}

// write chosen elements of List to file
IceCream* writingInFile(FILE* fp, IceCream* list, int numbers[])
{
    int sizeArr = sizeof(numbers) / sizeof(numbers[0]);
    int i;
    IceCream newList[sizeArr];
    for(i=0; i<sizeArr; i++)
        newList[i] = list[numbers[i]];
    fwrite(newList,sizeof(IceCream),sizeArr,fp);
    fclose(fp);

    return readingInFile(sizeArr);
}

// Reading the chosen elements
IceCream* readingInFile(int sizeList)
{
    IceCream* list = NULL;

    FILE* fp = fopen(fileName, "rb");

    list = (IceCream *)malloc(sizeList*sizeof(IceCream));
    if(list == NULL) exit(1);

    fread(list,sizeof(IceCream),sizeList,fp);
    fclose(fp);

    return list;
}
