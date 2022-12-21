#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Създайте структура служител, съдржаща информация за име, брутна заплата и пол.
//Създайте елемент за списък със същата информация.
//Напишете функция която записва в двоичен файл файл информацията част на списъка.
//Името на гайла е параметър на функцията
typedef struct Employee
{
    char name[20];
    double salary;
    char gender[2]; //M for male F for Female
}Employee;
Employee* arr;
int count=0;

void AddElement(char *name,int salary,char gender)
{
    arr=(Employee*)realloc(arr,sizeof(Employee)*(++count));
    if(arr==NULL)return;
    strcpy(arr[count-1].name,name);
    arr[count-1].salary=salary;
    strcpy(arr[count-1].gender,gender);
}
void WriteToBinary()
{
    FILE *fp = fopen("binfile.bin","wb");
    if(fp==NULL){
            printf("Couldn't open file to write in");
            exit(1);
    }
    else
    if(fwrite(arr,sizeof(Employee),count,fp)!=count)
        printf("Problem writing to the binary");
    fclose(fp);
}
//Напишете функция която върща сумата от заплатите на жените ,имената, на който започват с буква по-голяма от М

int sumofsalaryM(Employee *female,double salary)
{
    int sum=0;

    for(int i=0;i<count;i++)
    {
        if(female[i]->gender[0] == 'F' && female[i].name[0] > 'M')
        {
            sum=+female[i].salary;
        }

    }

    return sum;
}

void aboveonehalfofmaxsalary(Employee *employee,double salary)
{
    FILE *fp=fopen("list.txt","w");
    if(fp==NULL)return;
    double max=0;
    double temp=0;
    for(int i=0;i<count;i++)
    {
        if(employee[i].salary>employee[i+1].salary)
        {
           max=employee[i].salary;
        }
        else
        {
            max=employee[i+1].salary;
        }
        temp=max/2;
        if (employee[i].salary>temp)
        {
            fprintf(fp,"Name:%s Gender: %s have salary %lf which is above 1/2 of max: %lf salary",employee[i].name,employee[i].gender,employee[i].salary,max);
        }
    }
        fclose(fp);

}

// remove all employee with starting 'A'
void rmvEmployeeA()
{
    int i,j;
    for(i=0; i<count; i++)
    {
       if(arr[i].name[0] == 'A'){
            for(j=i+1;j<count;j++)
            {
                arr[j-1] = arr[j];
            }
        count--;
       }
    }

    arr = (Employee *)realloc(arr, count*sizeof(Employee));
}

void main()
{

}


