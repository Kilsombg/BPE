#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
1. Трябва да опишете структура, която да съхранява информация за световните кино звезди.
Съхраняваната информация за всяка кино звезда е: име на артиста, възраст, държава, спечелени приходи
до сега и брой статуетки "Оскар".
Използвайки описаната структура, напишете функция, която добавя нов артист опашъчно.
Функцията има следния прототип.
void AddNewArtist(List* root)

2. Напишете функция, която по подаден списък от артисти, и приход, връща списък с
артисти с доход, по-голям от подадения (списъкът, който връща да се реализира чрез стек).
Фунцкията има следния прототип
List* ReturnCertainIncomeArtistsList(List* root, float income)

3. Напишете функция, която попълва списък с данни от файл стеково. Функцията има прототип:
LIST* CreateStackList(List* root, FILE* fp)
*/

typedef struct{
    char name[20];
    int age;
    char country[20];
    double income;
    int oscars;
}Star;

// Function declaration
void AddNewArtist(Star* list);
void PrintList(Star* list, int sizeList);
void primaryList();
Star* ReturnCertainIncomeArtistsList(Star* list, float income);


// Global variables
const char *fileName = "oscars.bin";
Star* List = NULL;
Star* incomeList = NULL;
int size = 0;
int sizeIncome = 0;

int main(void)
{
    primaryList();
    PrintList(List, size);

    if(List != NULL) {
    AddNewArtist(List);
    PrintList(List,size);
    }

    incomeList = ReturnCertainIncomeArtistsList(List, 5000);
    PrintList(incomeList, sizeIncome);

    return 0;
}


// Добавя нов артист в списъка
void AddNewArtist(Star* list)
{
    Star star;
    strcpy(star.name, "Mark");
    star.age = 35;
    strcpy(star.country, "New Zeland");
    star.income = 15234.43;
    star.oscars = 3;

    list = (Star *)realloc(list, ++size*sizeof(Star));
    if(list == NULL) exit(1);

    list[size-1] = star;
}

// primary list
void primaryList()
{
    size = 4;
    List = (Star *)malloc(size*sizeof(Star));

    // Star 1
    strcpy(List[0].name, "Patric");
    List[0].age = 24;
    strcpy(List[0].country, "Bonavia");
    List[0].income = 4560;
    List[0].oscars = 0;

    // Star 2
    strcpy(List[1].name, "Tera");
    List[1].age = 65;
    strcpy(List[1].country, "Graduva");
    List[1].income = 160076.43;
    List[1].oscars = 4;

    // Star 3
    strcpy(List[2].name, "Mery");
    List[2].age = 16;
    strcpy(List[2].country, "Gopo");
    List[2].income = 1450;
    List[2].oscars = 0;

    // Star 4
    strcpy(List[3].name, "Tom");
    List[3].age = 28;
    strcpy(List[3].country, "Werian");
    List[3].income = 10000;
    List[3].oscars = 1;
}

// Print list
void PrintList(Star* list, int sizeList)
{
    printf("Printing list:\n");
    int i;
    for(i=0; i<sizeList; i++)
    {
        printf("name: %s\n", list[i].name);
        printf("age: %d\n", list[i].age);
        printf("country: %s\n", list[i].country);
        printf("income: %g\n", list[i].income);
        printf("oscars: %d\n\n", list[i].oscars);
    }
}


// Make a star list with income bigger than the given
Star* ReturnCertainIncomeArtistsList(Star* list, float income)
{
    Star *newList = NULL;
    int i;
    for(i=0; i<size; i++)
    {
        if(list[i].income > income)
        {
            newList = (Star *)realloc(newList, ++sizeIncome*sizeof(Star));
            if(newList == NULL) exit(1);

            newList[sizeIncome-1] = list[i];
        }
    }
    return newList;
}


// Create stack list
Star* CreateStackList(Star* list, FILE* fp)
{
    fp = fopen(filename, "rb");
    if(fp == NULL) exit(1);

    Star star;
    int i;

    while(1)
    {
        fread(&star, sizeof(Star), 1, fp);
        if(feof(fp)) break;

        list = (Star *)realloc(list, ++size*sizeof(Star));
        if(list == NULL) exit(1);
        for(i=size-1; i>0; i--)
            list[i] = list[i-1];
        list[0] = star;
    }
    return list;
}
