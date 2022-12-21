#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Трябва да изградите структура item, която представлява продукт в магазин. Структурата трябва да има следните
полета: Име на продукт(30 знака). ID на продукт(цяло число), срок на годност(низ с формат ГГГГ.ММ.ДД),
цена на продукт (реално число).

Използвайте така създадената структура за да изградите логика за свързан списък с име List. напишете създаването
на нов елемент и попълването му с информация от бинарен файл с име input.bin. Напишете добавянето на елемента в списък
чрез стекова логика.

Напишете функция expiresIn(), която приема за параметри дата - низ, който е във формата ГГГГ.ММ.ДД и начало на
списък, а изкарва на екрана всички продукти, които изтичат след тази дата(име и цена на продукта).

Напишете функция isIn(), която приема за параметър ID на продукт и начало на списък и връща указател към елемент
от списъка ако го има във вашия свързан списък или NULL ако няма такъв елемент.

Напишете функция ADD(), която получава елемент от тип структура item и елемент от тип списъка, след който
да добави елемента, който е получила.
*/


typedef struct{
    char name[30];
    int ID;
    char expireDate[11];
    float price;
}ITEM;

// Function declaration
void createItem();
ITEM mkItem();
void ADD(ITEM item, ITEM itemList);
void primaryItem();
void Writing();
void printList(ITEM *list, int listSize);
void expiresIn(char expire[], ITEM *list);
ITEM *isIn(int ID, ITEM *list);

// Global variables
ITEM *List = NULL;
int size = 0;

int main(void)
{
    primaryItem();
    Writing();
    createItem(); // Puts first element to the List, in that way the list has two times the first element (apple),
                  // this is in the input.bin

    ITEM newItem;
    newItem = mkItem();
    ADD(newItem, List[0]);
    printList(List, size);

    printf("\n\nExpire list:\n");
    expiresIn("2025.07.25",List);

    ITEM *needItem = isIn(101,List);
    if(needItem != NULL)
    {
        printf("\n\nItem in list:\n");
        printf("name: %s\n", needItem->name);
        printf("price: %g\n\n", needItem->price);

    }else printf("There is no item with ID 101");
    return 0;
}

// Create item
void createItem()
{
    // make item
    ITEM item;
    // put values to the item
    FILE *fp = fopen("input.bin", "rb");
    fread(&item,sizeof(ITEM),1,fp);

    List = (ITEM *)realloc(List, ++size*sizeof(ITEM));
    if(List == NULL) exit(1);

    // put item in the first place of the list as a stack
    int i;
    for(i=size-1; i>0; i--)
        List[i] = List[i-1];
    List[0] = item;

    fclose(fp);
}

// Print list
void printList(ITEM *list, int listSize)
{
    int i;
    printf("\nItem list:\n");
    for(i=0; i<listSize; i++)
    {
        printf("name: %s\n", list[i].name);
        printf("ID: %d\n", list[i].ID);
        printf("expireDate: %s\n", list[i].expireDate);
        printf("Price: %g\n\n", list[i].price);
    }
}

// Writing
void Writing()
{
    FILE *fp = fopen("input.bin","wb");
    if(fp == NULL) exit(1);

    fwrite(List,sizeof(ITEM),1,fp);

    fclose(fp);
}

// Primary item
void primaryItem()
{
    List = (ITEM *)malloc(2*sizeof(ITEM));
    if(List == NULL) exit(1);
    size = 2;

    // Item 1
    strcpy(List[0].name, "apple");
    List[0].ID = 101;
    strcpy(List[0].expireDate, "2022.10.19");
    List[0].price = 15.11; // Do you know what is 15.11

    // Item 2
    strcpy(List[1].name, "juice");
    List[1].ID = 103;
    strcpy(List[1].expireDate, "2065.12.24");
    List[1].price = 7.5;
}

 // Add element after given element from List
void ADD(ITEM item, ITEM itemList)
{
    int i,j;
    for(i=0; i<size; i++)
        if(!strcmp(List[i].name, itemList.name) &&
           List[i].ID == itemList.ID &&
           !strcmp(List[i].expireDate, itemList.expireDate) &&
           List[i].price == itemList.price)
    {
        List = (ITEM *)realloc(List, ++size*sizeof(ITEM));
        if(List == NULL) exit(1);

        for(j=size-1;j>i+1;j--)
            List[j] = List[j-1];

        List[i+1] = item;
        break;
    }
    else {
        printf("There is not a such item in the list!");
    }
}

// Make a item
ITEM mkItem()
{
    ITEM item;

    printf("name: ");
    scanf(" %s", item.name);
    printf("ID: ");
    scanf("%d",&item.ID);
    printf("expireDate: ");
    scanf(" %s", item.expireDate);
    printf("price: ");
    scanf("%f", &item.price);

    return item;
}


// Funciton for expire products
void expiresIn(char expire[], ITEM *list)
{
    int i;
    int year[2], month[2], day[2];

    // expireDate
    // this could be much easier with making another function instead of typing this, but...
    year[0] = expire[0] * 1000 + expire[1] * 100 + expire[2] * 10 + expire[3] * 1;
    month[0] = year[0] * 100 + expire[5] * 10 + expire[6] * 1;
    day[0] = month[0] * 100 + expire[8] * 10 + expire[9] * 1;

    for(i=0; i<size; i++)
    {
        // expireDate of the elements
        year[1] = list[i].expireDate[0] * 1000 + list[i].expireDate[1] * 100 + list[i].expireDate[2] * 10 + list[i].expireDate[3] * 1;
        month[1] = year[1] * 100 + list[i].expireDate[5] * 10 + list[i].expireDate[6] * 1;
        day[1] = month[1] * 100 + list[i].expireDate[8] * 10 + list[i].expireDate[9] * 1;

        if(day[1] < day[0])
        {
            printf("name: %s\n", list[i].name);
            printf("name: %g\n\n", list[i].price);
        }
    }
}

// Check if product is in the list
ITEM *isIn(int ID, ITEM *list)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(list[i].ID == ID)
            return &list[i];
    }
    return NULL;
}
