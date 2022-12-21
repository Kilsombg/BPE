#include<stdio.h>
#include<string.h>

/* Стамат е начинаещ администратор в училище и директора му поставя за задача да реализира приложение, което да менажира успеха на учениците по няколко дисциплини в даден клас. За целта той е замислил да съхранява данните за един ученик в подходяща структура, която пази информация за имената на ученика – всяко до 15 знака(три на брой), номер в класа – 5 цифрено число и текущи оценки по предметите. Предметите, за които пази информация са организирани в следния вид: математика, български и програмиране (оценките могат да бъдат не повече от 10 на брой за учебната година и са в рамките на стойности цели числа от 2 до 6).

Реализирайте подходяща форма за съхранение и обработка на информация за много ученици.

Първоначално на Стамат му е предоставен текстови файл с данните на учениците записани в следният вид за всеки ученик:

<номер в клас>: <Три имена> ; Mat: <оценки> BG: <оценки> IT: <оценки>

Пример: 17113: Ivan Ivanov Ivanov; Mat:6 6 6 BG: 6 5 6 4 4 IT: 6 3

  Прочетете от файла всички ученици и ги съхранете във временната памет на приложението.

След като Стамат има всички ученици от файла на директора то той трябва да прави обработка върху получените данни. Обработката се реализира в следните команди:

ADD grade <предмет> <оценка> <номер в клас> - добавя оценка по даден предмет на ученик с посоченият номер.

Calculate grades <номер на клас> - смята средният успех по всички предмети на посочения клас. Клас се дефинира от първите три знака на номера (17113 е клас 171, а ученика е с номер 13 в класа).

ADD student <три имена на ученика> <номер на клас> - регистрира нов ученик в училището, който все още няма оценки.

END – записва данните, с които до момента приложението е работило в бинарен файл.
*/


struct Predmet
{
    int math[11];
    int bel[11];
    int it[11];
};
typedef struct Predmet Predmet;

struct Student
{
    char name[16];
    char surName[16];
    char famName[16];
    int classNum;
    struct Predmet subject;
};
typedef struct Student student;
student *data;
int counter = 1;

void AddGrade(char *predmet, int grade, int cnum);
double CalcGrades(int clas);
void AddStudent(char *name, char *surname, char *famname, int classNum);
void Writing();

int main(void)
{


    return 0;
}

void AddStudent(char *name, char *surname, char *famname, int classNum)
{
    data = (student *)realloc(data, ++counter);
    if(data == NUll) {} // proverka
    strcopy(data[counter - 1].name, name);
    strcopy(data[counter - 1].surName, surname);
    strcopy(data[counter - 1].famName, famname);
    data[counter -1].classNum = classNum;
}

double CalcGrades(int clas)
{
    double grades = 0;
    int broi=0;
    for(int i=0; i<counter; i++)
    {
        if(data[i].classNum/100 == clas)
        {
            for(int j=0; j<11; j++)
            {
                if(data[i].subject.math[j] != 0)
                {
                    broi++; grades += data[i].subject.math[j];
                }

                if(data[i].subject.bel[j] != 0)
                {
                    broi++; grades += data[i].subject.bel[j];
                }

                if(data[i].subject.it[j] != 0)
                {
                    broi++; grades += data[i].subject.it[j];
                }
            }
        }
    }
    return grades/broi;
}

void AddGrade(char *predmet, int grade, int cnum)
{
    for(int i=1; i<counter, i++)
    {
        if(data[i].classNum == cnum)
        {
            if(strcmp(predmet, "math") == 0)
            {
                int j;
                for(j=1; j<11; j++)
                {
                    if(data[counter - 1].subject.math[j] == 0)
                        data[counter - 1].subject.math[j] = grade;
                }
                if(j>10) printf("too much grades, sorry");
            }
            else
            if(strcmp(predmet, "bg") == 0)
            {
            int j;
                for(j=1; j<11; j++)
                {
                    if(data[counter - 1].subject.bg[j] == 0)
                        data[counter - 1].subject.bg[j] = grade;
                }
                if(j>10) printf("too much grades, sorry");
            }
            else
            if(strcmp(predmet, "it") == 0)
            {
                int j;
                for(j=1; j<11; j++)
                {
                    if(data[counter - 1].subject.it[j] == 0)
                        data[counter - 1].subject.it[j] = grade;
                }
                if(j>10) printf("too much grades, sorry");
            }
        }
    }
}

void Writing()
{
    FIle *fp = fopen("fail.bin","wb");
    if(fp == NULL) {} // proverka

        // буфера - това, което ще записваме (data[i])
        // размера на това, което ще записваме
        // колко пути ще се зпаисва
        // файла
        if(fwrite(data[i], sizeof(struct Student), counter, fp) != counter) {} //greshka v pisane
    close(fp);
}


void Chetene()
{
    File *fp = fopen("director.txt", "r");
    if(fp == NULL) {} // greshka
    char row[200];
    while(fp != EOF)
    {
        if(fgets(fp, 200, row) == NULL) {break;} // greshka
        data = (student *)realloc(data, ++counter);
        int classNum = (row[0] - '0') * 10000 + (row[1] - '0') * 1000 + (row[2] - '0') * 100 + (row[3] - '0') * 10 + (row[4] - '0') * 1;
        data[counter - 1].classNum = classNum;
        int temp = 0;
        int curr = 7;
        for(int i=curr; i<strlen(row);curr++, i++)
            if(row[i] != ' ')
        {
            data[counter-1].name[temp++] = row[i];
        }
        data[counter-1].name[temp] = '\0';
        curr++;
        for(int i=curr; i<strlen(row);curr++, i++)
            if(row[i] != ' ')
        {
            data[counter-1].surName[temp++] = row[i];
        }
        data[counter-1].surName[temp] = '\0';
        curr++;
        for(int i=curr; i<strlen(row);curr++, i++)
            if(row[i] != ' ')
        {
            data[counter-1].famName[temp++] = row[i];
        }
        data[counter-1].famName[temp-1] = '\0';
        cur += 5;
        int pos=0;
        for(int i=curr; i<strlen(row);i++,curr++)
        {
            if(row[i] >= '2' && row[i] <= '6') data[counter-1].subject.math[pos++] = row[i] - '0';
            else
                if(row[i] == ' ') continue;
            else break;
        }
        cur += 4;
        for(int i=curr; i<strlen(row);i++,curr++)
        {
            if(row[i] >= '2' && row[i] <= '6') data[counter-1].subject.math[pos++] = row[i] - '0';
            else
                if(row[i] == ' ') continue;
            else break;
        }
    }
    fclose(fp);
}
