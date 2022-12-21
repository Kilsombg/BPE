#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * Library Managment System *

 - Make a data for book         ^^^
 - Make a series of books
 - Print the list of books      ^^^
 - Store it ( in a file )       ^^^
 - Read the data from the file  ^^^
 - Make a remove book function  ^^^
 - Already exist book checking  ^^^
 - Add books to binary file
 - Protection for loosing data
 - Make a search:               ^^^
    - by name                   ^^^
    - by autor                  ^^^
    - by year (Maybe)           ^^^
    - by genre                  ^^^
    - by favorite               ^^^
    - etc.
- Make favorite books
- Make several lists?
 - Try to make a UI?
                            */


typedef struct TBook
{
    char name[30];
    char autor[40];
    int year;
    char genre[20];
} Book;

#define NL printf("\n")

// Function declaration
Book mkBook();
void insertBook(Book** books, int *size);
void removeBook(Book books[], int *size);
void printBooks(Book books[], int size);
void Writing(Book* books, int count);
void Reading(Book** books, int* count);
void search(Book* books, int size);

// Global variables
const char* binaryFile = "data";


int main(void)
{
    Book *pB = NULL;
    int size = 0;
    char choice[10];

  //  Reading(&pB, &size);

    while(1)
    {
       printf("Choose to Insert, Remove, Search, Print, Read, Write or END: ");
       scanf(" %[^\n]s", &choice);

       if(!strcmp(choice, "END")) break;

       if(!strcmp(choice, "Insert")) insertBook(&pB, &size);
       if(!strcmp(choice, "Remove")) removeBook(pB, &size);
       if(!strcmp(choice, "Search")) search(pB, size);
       if(!strcmp(choice, "Print")) printBooks(pB, size);
       if(!strcmp(choice, "Read")) Reading(&pB, &size);
       if(!strcmp(choice, "Write")) Writing(pB, size);
    }

    free(pB);
    return 0;
}

// Insert the book to the list
void insertBook(Book** books, int *size)
{
    int i;

    // Choose what book to insert
    Book book = mkBook();

    for(i=0; i<*size; i++)
        if(!strcmp(book.name,(*books)[i].name)){printf("Already in the list!\n"); return; }

    // Inserting the book
     *books = (Book *)realloc(*books, ++(*size) * sizeof(Book));
    if(*books == NULL) exit(1);

   (*books)[*size - 1] = book;
}

// data of a book
Book mkBook()
{
    Book book;

    printf("name: ");
    scanf(" %[^\n]s", &book.name);
    printf("autor: ");
    scanf(" %[^\n]s", &book.autor);
    //printf("genre: ");
    //scanf(" %[^\n]s", &book.genre);
    printf("year: ");
    scanf("%d", &book.year);
    NL;

    return book;
}

// remove a book by name
void removeBook(Book books[], int *size)
{
    char name[30];
    printf("Write the name of the book you want to remove: ");
    scanf(" %[^\n]s", &name);
    NL;

    int i,j;
    for(i=0; i<*size; i++)
        if(!strcmp(books[i].name, name))
        {
           for(j=i+1; j<*size; j++)
                books[j-1] = books[j];
            // make if size comes to 0
            if(!(*size - 1)) {--(*size); return;}
           books = (Book *)realloc(books, --(*size) * sizeof(Book));
           if(books == NULL) exit(1);
           return;
        }
}

// print the list of books
void printBooks(Book books[], int size)
{
    int i;

    for(i=0; i<size; i++)
    {
        printf("\nname: %s\n", books[i].name);
        printf("autor: %s\n", books[i].autor);
        // printf("genre: %s\n", books[i].genre);
        printf("year: %d\n\n", books[i].year);
    }
}

// write to binary file
void Writing(Book * books, int count)
{
    FILE* fp = fopen(binaryFile, "wb");
    if(fp == NULL) exit(1);

    fwrite(books, sizeof(Book),count, fp);

    fclose(fp);
}


// Read binary file
void Reading(Book** books, int* count)
{
    *count = 0;
    if(*books != NULL) {free(*books); *books = NULL;}

    FILE* fp = fopen(binaryFile, "rb");
    if(fp == NULL) exit(1);
    Book book;


    while(1)
    {
        if(fread(&book, sizeof(Book),1, fp) != 1) break;


        *books = (Book *)realloc(*books, ++(*count)*sizeof(Book));
        if(*books == NULL) exit(1);

        (*books)[*count-1] = book;
    }

    fclose(fp);
}


// Search funciton
// name - 1, autor - 2, year - 3, genre - 4, favorite - 5
void search(Book* books, int size)
{
    int mode=0, year, i, find=0;
    char choice[10];
    char searchItem[20];
    printf("Search by (name, autor, year, genre or favorite): ");
    scanf(" %s", &choice);

    // Check what search
    if(!strcmp(choice, "name")) mode = 1;
    else if(!strcmp(choice, "autor")) mode = 2;
    else if(!strcmp(choice, "year")) mode = 3;
    else if(!strcmp(choice, "genre")) mode = 4;
    else if(!strcmp(choice, "favorite")) mode = 5;

    // Print the result
    if(strcmp(choice, "favorite")) printf("Write %s: ", choice);
    else printf("Favorite books:\n");

    if(!strcmp(choice, "year")) scanf("%d", &year);
    else scanf(" %s", &searchItem);

    switch(mode){
    case 1:
        for(i=0; i<size; i++)
            if(!strcmp(books[i].name,searchItem)) {printBooks(&books[i],1); find=1;}
            break;
    case 2:
        for(i=0; i<size; i++)
            if(!strcmp(books[i].autor,searchItem)) {printBooks(&books[i],1); find=1;}
            break;
    case 3:
        for(i=0; i<size; i++)
            if(books[i].year == year) {printBooks(&books[i],1); find=1;}
        break;
    case 4:
        for(i=0; i<size; i++)
            if(!strcmp(books[i].genre,searchItem)) {printBooks(&books[i],1); find=1;}
            break;
    /*case 5:
        for(i=0; i<size; i++)
            if(!strcmp(books[i].favorite,searchItem)) {printBooks(&books[i],1); find=1;}
            break; */
    }

    if(!find) printf("\nDon't find compatible book.\n\n");
}
