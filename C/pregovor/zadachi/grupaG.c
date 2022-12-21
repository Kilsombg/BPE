#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
1. �������� ��������� ������, ��������� ���������� �� ���, ������ � ���� �� ���������� � ������.
�������� ������� �� ������ ��� ������ ����������. �������� �������, ����� ������� � ������� ����
��������������� ���� �� �������. ����� �� ����� � ��������� �� ���������.

2. �������� �������, ����� ����� ������ �� ��������� �� ���������, �������, �� ����� �������� �
����� ��-����� �� �.

3. �������� ������� maxBudget, ����� ����� ����������� ������ �� ��������� � �������.
����������� �������, ����� ������� ������ �� ������� � ������, ��-����� �� 1/3*max
(max � ������������ ������ � �������), ���� ���������� ��������� maxBudget.

4. ����������� �������, ����� ������� � ���������� �� ������ ������ �� ���������, ����� ��
������ � ������ �� ������, ���� ������, �� ������� ������ �� ��������� ���� ���������� �� ���������, �����
�� 40%.
*/

typedef struct{
    char name[30];
    float budget;
    int months;
}Project;

#define N 4

// Function declaration
void Reading(char name[]);
void Writing(char name[]);
void primaryData();
void PrintList(Project *list, int size);
float sumBelowP();
float maxBudget();
Project *mkThirdProjectList();
void PrintProjects();

// Global variables
Project *projects;
Project *OneThirdProjects;
int size = N;
int OneThirdSize = 0;

int main(void)
{
    // primaryData();
    // Writing("Projects");
    Reading("Projects");
    // PrintList(projects, size);

    printf("Sum of budgets below P: %g\n\n", sumBelowP());

    OneThirdProjects = mkThirdProjectList();
    printf("One third budget projects:\n");
    PrintList(OneThirdProjects, OneThirdSize);

    PrintProjects();

    return 0;
}


// Writing
void Writing(char name[])
{
    FILE *fp = fopen(name, "wb");
    if(fp == NULL) exit(1);

    fwrite(projects,sizeof(Project),size,fp);

    fclose(fp);
}

// Reading
void Reading(char name[])
{
    projects = (Project *)malloc(size*sizeof(Project));
    if(projects == NULL) exit(1);

    FILE *fp = fopen(name, "rb");
    if(fp == NULL) exit(1);

    fread(projects,sizeof(Project),size,fp);

    fclose(fp);
}

// primary list
void primaryData()
{
    projects = (Project *)malloc(N*sizeof(Project));
    if(projects == NULL) exit(1);

    int i;
    for(i=0; i<N; i++)
    {
        projects[i].budget = 750 * (i+1) + (i*i) * 235;
        projects[i].months = i+5;
    }

    strcpy(projects[0].name, "A_Project");
    strcpy(projects[1].name, "G_Project");
    strcpy(projects[2].name, "P_Project");
    strcpy(projects[3].name, "Z_Project");
}


// PrintList
void PrintList(Project *list, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("name: %s\n", projects[i].name);
        printf("budget: %g\n", projects[i].budget);
        printf("months: %d\n\n", projects[i].months);
    }
}

// Budget sum of projects below P
float sumBelowP()
{
    float sum = 0;
    int i;

    for(i=0; i<size; i++)
        if(projects[i].name[0] < 'P') sum += projects[i].budget;

    return sum;
}


// Find max budget
float maxBudget()
{
    float max = projects[0].budget;
    int i;
    for(i=1; i<size; i++)
        if(projects[i].budget > max) max = projects[i].budget;
    return max;
}


// Make a list of projects with less than 1/3 max budget
Project *mkThirdProjectList()
{
    Project *newList = NULL;
    int i;
    float oneThirdBudget = maxBudget() / 3;
    for(i=0; i<size; i++)
        if(projects[i].budget < oneThirdBudget)
        {
            newList = (Project *)realloc(newList, ++OneThirdSize*sizeof(Project));
            if(newList == NULL) exit(1);

            newList[OneThirdSize-1] = projects[i];
        }
    return newList;
}


// Print name of the projects and their total budget and net budget
void PrintProjects()
{
    Project *newList = (Project *)malloc(size*sizeof(Project));
    if(newList == NULL) exit(1);
    int i;
    float totalBudget = 0;

    // Copy the list
    for(i=0; i<size; i++){
        newList[i] = projects[i];
        totalBudget += projects[i].budget;  // get total budget
    }

    printf("Porjects:\n");
   PrintList(newList, size);
   printf("TotalBudget: %g\n",totalBudget);
   printf("netbudget: %g\n", totalBudget * 0.6);

}
