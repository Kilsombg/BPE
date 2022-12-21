#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Store{
    char name[31];
    int ID;
    char expirydate[11];
    double price;
};
typedef struct Store Store;

Store* arr = NULL;
int countproducts=0;

void AddItem(char *name,int ID,char *expirydate,double price)
{
    arr=(Store*)realloc(arr,sizeof(Store)*(++countproducts));
    if (arr==NULL)
    {
        printf("Error!");
        return;
    }
    strcpy(arr[countproducts-1].name,name);
    arr[countproducts-1].ID=ID;
    strcpy(arr[countproducts-1].expirydate,expirydate);
    arr[countproducts-1].price=price;
    printf("The item was add to your list;\n ");
}

void WriteToBinary(Store *arr)
{
    FILE *fp=fopen("in.bin","wb");
    if (fp==NULL)
    {
        printf("Error opening this file");
        return;
    }
    if(fwrite(arr,sizeof(Store),countproducts,fp)!=countproducts)
    {
        printf("reading error!");
        return;
    }

    printf("The items was added to binary file");
    fclose(fp);
}
//zadacha 2
void printitemswithpriceAbove(double price)
{
        printf("\nItems with price above are:\n");
        for (int i=0;i<countproducts;i++)
        {
            if(arr[i].price>price)
                printf("%s\n",arr[i]);
        }
}

//zadacha 3

void ReadToBinary()
{
    FILE *fp=fopen("in.bin","rb");
    if (fp==NULL)
    {
        printf("Error opening this file");
        return;
    }

    Store store;

    while(1)
    {
        fread(&store,sizeof(Store),1,fp);
         if(feof(fp)) break;

        arr = (Store *)realloc(arr,++countproducts*sizeof(Store));
        if(arr == NULL) exit(1);

        arr[countproducts-1] = store;
    }

}

void printList()
{
    int i;
    for(i=0; i<countproducts; i++)
    {
        printf("name: %s\n", arr[i]);
    }
}

void writetoText(Store *arr)
{
    printf("Text file information:\n");
    FILE *fp=fopen("outTxt","w");
    if(fp==NULL)
    {
        printf("Error");
        exit(10);
    }
    for(int i=0;i<countproducts;i++)
    {
            fprintf(fp,"%s  %d  %s  %lf \n",arr[i].name,arr[i].ID,arr[i].expirydate,arr[i].price);
            printf("%s  %d  %s  %lf \n",arr[i].name,arr[i].ID,arr[i].expirydate,arr[i].price);
    }
    fclose(fp);
    printf("The information is written in text file");
}


int main()
{
   // AddItem("Milk",1,"2022.05.24",3.56);
    //AddItem("Eggs",2,"2022.05.28",3.67);
    //AddItem("Bananas",2,"2022.05.28",3.69);
    //WriteToBinary(arr);
    ReadToBinary();
    printList();

   // printitemswithpriceAbove(3.58);
   // writetoText(arr);
    return 0;
}
