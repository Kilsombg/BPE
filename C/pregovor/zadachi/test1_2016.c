#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Във файла phones.bin е зпаисана информация за мобилни телефони в следния формат:
length of brand | brand | length of model | model | number | price |

Полетата имат следните типове:
lenght of brand - int
brand - низ от тип char
length of model - int
model - низ от тип char
number - int
price - double

Задача: Във файл sony.bin да се запишат всички телефони от марката "sony", които имат цена,
по-голяма от среданта цена на всички телефони, записани във файла, в следния формат:
| price | number | length of brand | brand | length of model | model |
*/

typedef struct{
    int lenghtOfBrand;
    char brand[100];
    int lengthOfModel;
    char model[20];
    int number;
    double price;
} Phone;

#define N 6

// Function declaration
void primaryList();
void Writing();
void Reading();
void PrintList(Phone *list, int size);


// Global variables
Phone *phones = NULL;
int size = 0;

int main(void)
{
   // primaryList();
   // Writing();
    Reading();
    PrintList(phones,size);

    return 0;
}

// Primary data
void primaryList()
{
    size = N;
    phones = (Phone *)malloc(N*sizeof(Phone));
    if(phones == NULL) exit(1);
    int i;
    for(i=0; i<N; i++)
    {
        phones[i].lenghtOfBrand = 100;
        phones[i].lengthOfModel = 20;
        phones[i].number = (i+1) * 100;
        phones[i].price = 300*(i+1) - 40*i;
        strcpy(phones[i].brand, "sony");
        strcpy(phones[i].model, "Xperia");
    }

    strcpy(phones[3].brand, "samsung");
    strcpy(phones[3].model, "S10");
    strcpy(phones[4].brand, "huawei");
    strcpy(phones[4].model, "P30");
}


// Writing
// length of brand | brand | length of model | model | number | price |
void Writing()
{
    FILE *fp = fopen("phones.bin", "wb");
    if(fp == NULL) exit(1);

    int i;
    int lenOfBrand, lenOfModel;

    for(i=0; i<size; i++)
    {
        lenOfBrand = phones[i].lenghtOfBrand;
        lenOfModel = phones[i].lengthOfModel;

        fwrite(&lenOfBrand, sizeof(int), 1, fp);
        fwrite("|",sizeof(char),1,fp);

        fwrite(phones[i].brand, lenOfBrand, 1, fp);
        fwrite("|",sizeof(char),1,fp);

        fwrite(&lenOfModel, sizeof(int), 1, fp);
        fwrite("|",sizeof(char),1,fp);

        fwrite(phones[i].model, lenOfModel, 1, fp);
        fwrite("|",sizeof(char),1,fp);

        fwrite(&(phones[i].number), sizeof(int), 1, fp);
        fwrite("|",sizeof(char),1,fp);

        fwrite(&(phones[i].price), sizeof(double), 1, fp);
        fwrite("|",sizeof(char),1,fp);
    }
    fclose(fp);
}

// Reading
// length of brand | brand | length of model | model | number | price |
void Reading()
{
    FILE *fp = fopen("phones.bin", "rb");
    if(fp == NULL) exit(1);
    int check;

    for(;;)
    {
        //if(feof(fp)) break;

        // This checks if it is end of file
        if(fread(&check, sizeof(int),1,fp) != 1) break;
        fseek(fp,-sizeof(int),SEEK_CUR); // returns one integer back

        phones = (Phone *)realloc(phones, ++size*sizeof(Phone));
        if(phones == NULL) exit(1);

        fread(&(phones[size-1].lenghtOfBrand), sizeof(int), 1, fp);
        int lenOfBrand = phones[size-1].lenghtOfBrand;
        fseek(fp,sizeof(char),SEEK_CUR);

        fread(phones[size-1].brand, lenOfBrand, 1, fp);
        fseek(fp,sizeof(char),SEEK_CUR);

        fread(&(phones[size-1].lengthOfModel), sizeof(int), 1, fp);
        int lenOfModel = phones[size-1].lengthOfModel;
        fseek(fp,sizeof(char),SEEK_CUR);

        fread(phones[size-1].model, lenOfModel, 1, fp);
        fseek(fp,sizeof(char),SEEK_CUR);

        fread(&(phones[size-1].number), sizeof(int), 1, fp);
        fseek(fp,sizeof(char),SEEK_CUR);

        fread(&(phones[size-1].price), sizeof(double), 1, fp);
        fseek(fp,sizeof(char),SEEK_CUR);
    }
    fclose(fp);
}

// Print list
void PrintList(Phone *list, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("length of brand: %d\n",list[i].lenghtOfBrand);
        printf("brand: %s\n",list[i].brand);
        printf("length of model: %d\n",list[i].lengthOfModel);
        printf("model: %s\n",list[i].model);
        printf("number : %d\n",list[i].number);
        printf("price : %g\n\n",list[i].price);
    }
}
