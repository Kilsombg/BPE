#include<stdio.h>

/* ������ 1:
 �� �� ������ �������� �� ��������� �� ���������� �� 5 �����. �� ����� ����� �� ������� ���������� ��:
 - ��� �� ����� (char[])
 - ����� (char[])
 - ������ �� �������� (int)
 - ���� (double)

 �� �� ���������� ������� �������:
 - �� ��������� �� ������������ �� �������
 - �� ����������� ���������� �� ������ �����, �������� ���� 2005 ������
 - �� ������� �� ����� �� ��� �� �����, ����� �� ������ �� �����������.
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





/* ������ 2
�� �� ������ �������� �� ��������� �� ����� �� �������� � ���� �������.
�� ����� ������� �� �������� ����� ��:
- ������������ (char[])
- ������������ (char[])
- ���� (double)
- ����������(int)
����� �� ���������� � �������� �� ������� �� ������������
�� �� ����������:
- ������� �� ��������� �� ������������ �� ������������ �� ����������
- ������� �� ��������� �� ������������ �� ��������� �������� � �������� � ���������� �� �������������
- �������, ����� ����� �������� ���� �� ���������� � ��������
*/

//typedef struct artikul()
