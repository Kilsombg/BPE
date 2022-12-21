#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
1. Създайте структура служител, съдържаща информация за име,
брутна заплата и пол. Създайте елемент на списък със същата информация.
Напишете функция, която записва в двоичен файл информационната част на
списъка. Името на файла е параметър на функцията.
2. Напишете функция, която връща сумата от заплатите на жените, имената,
на които започват с буква, по-голяма от М.
3. Дефинирайте функция, която създава списък от служители с брутна заплата, по-голяма от 1/2
max (max, е максималната заплата в списъка).
4. Напишете функция, която изтрива служителите чието име започва с А
*/

typedef struct{
    char name[20];
    int salary;
    char gender;
} Employee;

#define N 4

// Function declaration
void Writing(char name[]);
int SumSalary();
Employee *mkEmployees();
int maxSalary();
Employee *listHalfEmployee();
void PrintList(Employee *list, int listSize);
void rmvEmployeeA();


// Global Variables
Employee *employees;
Employee *halfMaxEmp;
int size = N;
int countHalf = 0; // size of the list of half salary employees

int main(void)
{
    employees = mkEmployees();
    int sumOfSalary = SumSalary();
    printf("Sum of salary : %d\n", sumOfSalary);
    Writing("data");
    halfMaxEmp = listHalfEmployee();
    PrintList(halfMaxEmp, countHalf);

    printf("\n\n");
    rmvEmployeeA();
    PrintList(employees, size);

    return 0;
}

// Make a test list
Employee *mkEmployees()
{
    Employee *testEmployees;
    testEmployees = (Employee *)malloc(N*sizeof(Employee));

    for(int i=0; i<N; i++)
    {
        testEmployees[i].gender = 'F';
        testEmployees[i].salary = 900 * (i+1);
    }
    testEmployees[2].salary += 500;

    strcpy(testEmployees[0].name, "Alicia");
    strcpy(testEmployees[1].name, "Molina");
    strcpy(testEmployees[2].name, "Teona");
    strcpy(testEmployees[3].name, "Zora");

    return testEmployees;
}

// Printing the list of employees
void PrintList(Employee *list, int listSize)
{
    for(int i=0; i<listSize; i++)
    {
        printf("name: %s\n", list[i].name);
        printf("salary: %d\n", list[i].salary);
        printf("genger: %c\n\n", list[i].gender);
    }
}

// Binary writing
void Writing(char name[])
{
    FILE *fp = fopen(name, "wb");
    if(fp == NULL) exit(1);

    fwrite(employees,sizeof(Employee),size,fp);

    fclose(fp);
}

// Sum of sallary of women and bigger than 'M'
int SumSalary()
{
    int sum = 0, i;

    for(i=0;i<size;i++)
    {
        if(employees[i].gender == 'F' && employees[i].name[0] > 'M')
            sum += employees[i].salary;
    }
   return sum;
}


// List of employees that have bigger sallary than 1/2 max
Employee *listHalfEmployee()
{
    float halfMax = (float)maxSalary() / 2.;
    Employee *newList = NULL;
    int i;

    for(i=0;i<N;i++)
    {
        if((float)employees[i].salary > halfMax)
        {
            newList = (Employee *)realloc(newList, ++countHalf * sizeof(Employee));
            if(newList == NULL) exit(1);

            newList[countHalf-1] = employees[i];
        }
    }
    return newList;
}

// return the max salary
int maxSalary()
{
    int max;
    max = employees[0].salary;
    for(int i=1;i<N;i++)
        if(employees[i].salary > max) max = employees[i].salary;
    return max;
}


void rmvEmployeeA()
{
    for(int i=0; i<size; i++)
    {
        if(employees[i].name[0] == 'A'){
            for(int j=i+1; j<size; j++)
                employees[j-1] = employees[j];
            size--;
        }
    }

    employees = (Employee *)realloc(employees, size*sizeof(Employee));
    if(employees == NULL) exit(1);
}
