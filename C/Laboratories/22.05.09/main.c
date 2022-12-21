#include<stdio.h>

/* Задача 1:
 Да се напише програма за обработка на информация за 5 книги. За всяка книга се въвежда информация за:
 - име на книга (char[])
 - авотр (char[])
 - година на издаване (int)
 - цена (double)

 Да се реализират отделни функции:
 - за въвеждане на информацията за книгите
 - за извежданена информация за всички книги, издадени след 2005 година
 - за търсене на книги по име на автор, което се задава от потребителя.
 */

 /*
 typedef struct TBook
 {
     char name[20];
     char autor[20];
     int year;
     double price;
 } Book;

Book *insertBook(Book books[], int *count);
void printBooks(Book books[]);
void printBook(Book books[]);
Book mkBook();

#define N 1
 int main(void)
 {
     Book *books = NULL;
     int count=0;
     int i;
     for(i=0; i<N; i++)
     {
         books = insertBook(books, &count);
     }

     printBooks(books);
     printBook(books);
     return 0;
 }

 Book *insertBook(Book books[], int *count)
 {
     Book book = mkBook();

     books = (Book *)realloc(books, ++(*count) * sizeof(Book));
     if(books == NULL) exit(1);

     books[*count - 1] = book;
     return books;
 }

 Book mkBook()
 {
     Book book;
     printf("name: ");
     scanf(" %[^\n]s", &book.name);
     printf("autor: ");
     scanf(" %[^\n]s", &book.autor);
     printf("year: ");
     scanf("%d", &book.year);
     printf("price: ");
     scanf("%lf", &book.price);
     return book;
 }

 void printBooks(Book books[])
 {
     int i;
     for(i=0; i<N; i++)
     {
         if(books[i].year > 2005)
         {
             printf("\nBook %d\n", i+1);
             printf("name: %s\n", books[i].name);
             printf("autor: %s\n", books[i].autor);
             printf("year: %d\n", books[i].year);
             printf("price: %g\n\n", books[i].price);
         }
     }
 }

 void printBook(Book books[])
 {
     char name[20];
     printf("Wirte the name of the book: ");
     scanf(" %[^\n]s", &name);
     int i;
     for(i=0; i<N; i++)
     {
         if(!strcmp(books[i].name, name))
         {
             printf("name: %s\n", books[i].name);
             printf("autor: %s\n", books[i].autor);
             printf("year: %d\n", books[i].year);
             printf("price: %g\n", books[i].price);
         }
     }
 }
*/





/* Задача 2
Да се напише програма за обработка на данни за артикули в един магазин.
За всеки артикул се въвеждат данни за:
- наименование (char[])
- производител (char[])
- цена (double)
- количество(int)
Броят на артикулите в магазина се въвежда от клавиатурата
Да се реализират:
- Функция за въвеждане от клавиатурата на информацията за артикулите
- Функция за сортиране по наименование на наличните артикули в магазина и принтиране на информаицията
- Функция, която връща средната цена на артикулите в магазина
*/

//typedef struct artikul()
