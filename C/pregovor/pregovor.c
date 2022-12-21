#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* 1. Да се напише програма, която намира лице на правоъгълник по зададени
    от клавиатурата две страни и го извежда на екрана.  */
    /*
    float a,b;
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("Area = %g", a*b); */


/* 3. Да се прочетат от клавиатурата 3 числа и да се изведе на екрана най-малкото от тях.  */
/*
int main(void){
    int x,y,z;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    if(x<y){
        if(x<z) printf("%d",x);
        else printf("%d",z);
    } else if(y<z) printf("%d",y);
        else printf("%d",z);
    return 0;
    }*/


/* Низове */
/*
int main(void)
{
    char s[] = "stjijr";
    char *p = s;
    int l=0;
    while(*p)
    {
        l++;
        p++;
    }
    printf("%d", l);

    return 0;
}*/


/* strcmp() */
/*
typedef struct{
int x;
char c;} Struct;
int main(void)
{   Struct a[4];
    a[0].x = 1;
    a[0].c = 'a';
    a[1].x = 2;
    a[1].c = 'b';
    a[2].x = 3;
    a[2].c = 'c';
    a[3].x = 4;
    a[3].c = 'd';
    for(int i=0; i<4; i++)
        if(a[i].c == 'b')
            for(int j=i+1; j<4; j++)
                a[j-1] = a[j];

    for(int i=0; i<3; i++)
    {
        printf("%d ", a[i].x);
        printf("%c\n", a[i].c);
    }


return 0;}

*/
/*
int main(void)
{
    char *a = malloc(4*sizeof(char));
    strcpy(a,"tri");
    char *p = a;
    if(a[0] == 'i') printf("yes");
    else printf("no");

return 0;}
*/

/*
typedef struct{
char name[20];}Name;

Name name1;
int main(void)
{
    strcpy(name1.name,"Alice");
    char *p;
    char *p2;
    char a[3];
    strcpy(a,"bcd");
    p2 = a;
    p = name1.name;
    if(!strcmp(*p2,"b")) printf("yes");
    else printf("no");
*/




/* Testing for loop */
/*
int main(void)
{
    int i,j;
    int sum=10;
    for(i=0;i<sum;i++)
    {
        if(i%2 == 0) sum--;
        printf("%d",i);
    }
    return 0;}
*/



/* fwrite() */
/*
struct Person{
    char name[20];
    int age;
}person[3],person2[3];

int main(void)
{
    FILE *fp = fopen("persons.bin","wb");
    if(fp == NULL) exit(1);
    strcpy(person[0].name,"name1");
    person[0].age = 1;
    strcpy(person[1].name,"name2");
    person[1].age = 2;
    strcpy(person[2].name,"name3");
    person[2].age = 3;

    fwrite(person,sizeof(struct Person),3,fp);
    fclose(fp);

    fp = fopen("persons.bin","rb");
    if(fp == NULL) exit(1);
    fread(person2,sizeof(struct Person),3,fp);
    fclose(fp);

    for(int i=0; i<3;i++)
    {
        printf("%s ",person2[i].name);
        printf("%d",person2[i].age);
    }
    return 0;
}*/


/* compare structures */
/*
struct{
    int x;
    char name[10];
}A,B;

int main(void)
{
    A.x = 10;
    A.x = 10;
    strcpy(A.name,"name");
    strcpy(B.name,"name");

    if(A == B) printf("yes");
    else printf("no");

    return 0;
}*/


/* Testing return printf value */
/*
int main(void)
{
    printf("printf value: %d\n", printf("abc")); // printf value = 3
    printf("printf value: %d\n", printf("abc%d",2)); // printf value = 4
    printf("printf value: %d\n", printf("abc%d",23)); // printf value = 5
}
*/


/* Freeing dynamic arrays */
/*
int main(void)
{
    int* arr = NULL;

    arr = (int *)realloc(arr, 3*sizeof(int));
    arr[0] = 2;
    printf("%d ", arr[0]);
    free(arr);

    arr = NULL; // you have to assing NULL to arr

    arr = (int *)realloc(arr, 2*sizeof(int));
    arr[0] = 1;
    printf("%d ", arr[0]);
    free(arr);

    return 0;
}
*/

/* string scanf() */

int main()
{
    char s[20],s1[32];
    scanf("%s",s1); fflush(stdin);
    scanf(" %[^\n]s",s); //fflush(stdin);

    printf(s);
    printf(s1);
    return 0;
}
