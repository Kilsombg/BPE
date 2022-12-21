#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Приют за бездомни животни се нуждае от софтуерно приложение. В приюта могат да бъдат
настанени животни в клетки със следните характеристики:
struct Cage
{
    Char type[10]; // Тип на животното - dog, cat, bird...
    int age; // Приблизителна възраст на животното
    Char id[10]; //Уникален идентификационен номер на животното
}

Всички клетки, в които биват настанени животни, се записват в бинарния файл newcomers.bin.

1. Имплементирайте функцията void load_newcomers(QueueNode* root), зареждаща в
линеен едносвързан FIFO списък (опашка) всички елементи от бинарния файл, даден по-горе.
Използвайте следния тип за възел на списъка:
struct QueueNode
{
    struct Cage node;
    struct QueueNode *next;
};

2. Имплементирайте функцията int animal_typecnt(QueueNode* root, char* animalType),
връщаща броя на животните от дадения като параметър тип, а опашката се предполага, че е заредена
в паметта на програмата и нейното начало бива подадено на тази функция.

3. След известно време животните трябва да бъдат обезпаразитени, но с по-голяма спешност са тези,
които са с най-малка възраст. Имплементирайте функцията StackNode* deworming(QueueNode* root), която
създава нов линеен едносвързан LIFO списък (стек), където най-младите животни ще бъдат обработени първи, a StackNode
има следното описание:
struct StackNode
{
    struct Cage cage;
    struct StackNode* next;
};

4. Имплементирайте функцията void store_animals(FILE *fp, StackNode* root), записваща в текстов файл
(отворен запис извън функцията) следните полета от елементите на стека: type, id.
*/


typedef struct
{
    char type[10];
    int age;
    char id[10];
} Cage;

typedef struct queueNode
{
    Cage node;
    struct queueNode* next;
} QueueNode;

typedef struct stackNode
{
    Cage cage;
    struct stackNode* next;
} StackNode;

// Function declaration
void load_newcomers(QueueNode* root);
void WritingInitialData();
void printList();
/*QueueNode* nullQueue(); */
void readBi();
void printCageList();
void printStackList(StackNode* root);
int animal_typecnt(QueueNode* root, char* animalType);
void store_animals(StackNode *root);
StackNode* mkStackList();
void swapStackNodes(StackNode* stack1, StackNode* stack2);
StackNode* deworming(QueueNode* root);

// Global variables
const char* filename = "newcomers.bin";
const char* txtFileName = "animals.txt";
QueueNode queueList;
StackNode* stackList;
StackNode* dewormStack;
Cage* List = NULL;
int size = 0;


int main(void)
{
   // WritingInitialData();
    //readBi();
    //printCageList();

    load_newcomers(&queueList);
    printList();

    int count = animal_typecnt(&queueList, "cat");
    printf("cats: %d\n", count);


    /*
    stack = deworming(&queueList);
    printf("stack = %s\n", stack->cage.type); */

    //printf("\nStack List:\n");
    //stackList = mkStackList();
    //swapStackNodes(stackList, stackList->next);
    //printStackList(stackList);

    printf("\nSorting stack list:\n\n");
    stackList = mkStackList();
   dewormStack = deworming(stackList);
   printStackList(dewormStack);

    store_animals(dewormStack);
    return 0;
}

//Read newcomers
void load_newcomers(QueueNode* root)
{
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) exit(1);

    Cage cage;
    QueueNode* cur = root;
    QueueNode* prv = NULL;

    while(1)
    {
        if(feof(fp)) break;
        fread(&cage, sizeof(Cage), 1, fp);

        cur->node = cage;
        cur->next = NULL;
        if(prv != NULL) prv->next = cur;

        prv = cur;
        cur = (QueueNode *)malloc(sizeof(QueueNode));
    }

    fclose(fp);
}

/*
// function that returns null queue
QueueNode* nullQueue()
{
    QueueNode* queue;

    strcpy(queue->node.type, "");
    strcpy(queue->node.id, "");
    queue->node.age = 0;

    queue->next = NULL;

    return queue;
} */

// Initial data
void WritingInitialData()
{
    FILE* fp = fopen(filename, "wb");
    if(fp == NULL) exit(1);

    Cage cages[4] = {
        {"cat", 2, "101"},
        {"dog", 5, "102"},
        {"bird", 1, "103"},
        {"cat", 7, "104"},
    };

    fwrite(cages, sizeof(Cage), 4, fp);

    fclose(fp);
}

// Read binary file
void readBi()
{
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) exit(1);
    Cage item;

    while(1)
    {
        fread(&item, sizeof(Cage), 1, fp);
        if(feof(fp)) break;

        List = (Cage *)realloc(List, ++size*sizeof(Cage));
        List[size-1] = item;
    }

    fclose(fp);
}

// printing cages
void printCageList()
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("type: %s\n", List[i].type);
        printf("type: %d\n", List[i].age);
        printf("type: %s\n\n", List[i].id);
    }
}

// Printing list
void printList()
{
    QueueNode* root = &queueList;
    while(1)
    {

        printf("type: %s\n", root->node.type);
        printf("age: %d\n\n", root->node.age);

        root = root->next;
        if(root->next == NULL) break;
    }
}

// count of animals with given type
int animal_typecnt(QueueNode* root, char* animalType)
{
    int count = 0;

    while(1)
    {
        if(root->next == NULL) break;

        if(!strcmp(root->node.type,animalType)) count++;
        root = root->next;
    }

    return count;
}


/*
// списък за обезпаразитяване
StackNode* deworming(QueueNode* root)
{
    StackNode* stackRoot;
    StackNode* curStack;
    StackNode* tmpStack;
    StackNode* prvStack;
    QueueNode* cur = root->next;

    stackRoot->cage = root->node;
    stackRoot->next = NULL;
    curStack = stackRoot;
    prvStack = NULL;

    while(1)
    {
        if(cur->next == NULL) break;

        // go through the stack list
        while(1)
        {
            if(curStack->next == NULL) break;

            if(cur->node.age < curStack->cage.age)
            {
                tmpStack = (StackNode *)malloc(sizeof(StackNode));
                tmpStack = curStack;

                curStack->cage = cur->node;
                curStack->next = tmpStack;

                if(prvStack != NULL) prvStack->next = curStack;
            }

            prvStack = curStack;
            curStack = curStack->next;
        }

        cur = cur->next;
    }

    return stackRoot;
}
*/

// returns dewroming list a.k.a sorting stack list
StackNode* deworming(QueueNode* root)
{
    StackNode* dewormingRoot = root;
    StackNode* cur;
    StackNode* rpnt = NULL;
    int swapped;

    do
    {
        swapped = 0;
        cur = dewormingRoot;

        while(cur->next != rpnt)
        {
            if(cur->cage.age > cur->next->cage.age)
            {
                swapStackNodes(cur, cur->next);
                swapped = 1;
            }
            cur = cur->next;
        }
        rpnt = cur;
    } while(swapped);

    return dewormingRoot;
}

// Transform Queue list to Stack list
StackNode* mkStackList()
{
    StackNode* root = (StackNode *)malloc(sizeof(StackNode));
    if(root == NULL) exit(1);
    StackNode* cur = (StackNode *)malloc(sizeof(StackNode));
    if(cur == NULL) exit(1);
    StackNode* prv;
    QueueNode* copyQueue = &queueList;

    root->cage = copyQueue->node;
    root->next = NULL;
    prv = root;
    copyQueue = copyQueue->next;

    while(1)
    {
        if(copyQueue->next == NULL) break;

        cur->cage = copyQueue->node;
        cur->next = NULL;
        prv->next = cur;

        prv = cur;
        cur = (StackNode *)malloc(sizeof(StackNode));
        copyQueue = copyQueue->next;
    }

    return root;
}

// Swap stack nodes
void swapStackNodes(StackNode* stack1, StackNode* stack2)
{
    Cage tmp;

    tmp = stack1->cage;
    stack1->cage = stack2->cage;
    stack2->cage = tmp;
}

// Print stack list
void printStackList(StackNode* root)
{
    StackNode* node;
    node = root;
    while(1)
    {
        if(node == NULL) break;

        printf("type: %s\n", node->cage.type);
        printf("id: %s\n\n", node->cage.id);

        node = node->next;
    }
}

// Store animals to txt file
void store_animals(StackNode* root)
{
    FILE* fp = fopen(txtFileName, "w");
    if(fp == NULL) exit(1);

    StackNode* animalRoot = root;

    while(1)
    {
        if(animalRoot == NULL) break;
        fprintf(fp, " %s %s", animalRoot->cage, animalRoot->cage.id);

        animalRoot = animalRoot->next;

    }

    fclose(fp);
}
