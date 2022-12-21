#include<stdio.h>
#include<stdlib.h>

/* ������ � ���������� � ��� ���� �� ����� ���������� �������. ��������� �� �� ������ ��������,
    � ����� �� �������� ������������� ������ � ������� ��������. �� ����� ������ �� ��������� ���������
    �� �������, ����� �� ������ ��� �� ��������, ���� � �������� �����. �������� � ��������� �� �������,
    ����� �� ������ ����� �� ������ � ����� �� �������.

    �� ����������� ���� ��������� ��������� �������� � �������.
    ������ ������ ����� ������ ��� �� ������ � ������ �� ����������� ������,
    � ������ �� ����� ������� �� �� ��������� ��� ������� �� �������, ����� ���� �� ����������� ��.

�� ������ ����� �� ���������� ��� �������:

Product

<��� �� �������>

<����>

<����� �� ��������>

���� ������� ������� ��� ������� � �� ������ � ������� � ��������.
��� ��� ������� �� ���� ������� �� ��������� �� ��������� ��������� � �� ���� �� �������� �� ����������.

Order

<�����>

<����� �� �������>

��� ��� ������� ���� ���������� ������� �� ��������� ���������, � �������� ������ ���� �� ��������� �� ��������.

��� ����� ���������� �� ������� ����������: Client <address> ordered <product name>

���������� ��������� ������ ��� ��������� �� ������� END  */



typedef struct TItem
{
    char name[20];
    double price;
    int ID;
} Item;

typedef struct TOrder
{
    char adress[50];
    int IDP;  // ID of the product
} Order;

#define SEP printf("\n################\n")
#define NL printf("\n")


Item mkItem();
Order mkOneOrder();
int rmProduct(int IDP, Item products[], int *countPr);
int rmOrder(int IDP, Order order[], int *countOr);
Item *mkProduct(Item products[], Order orders[], int *countPr, int *countOr);
Order *mkOrder(Item products[], Order orders[], int *countPr, int *countOr);
void Print(Item products[], Order orders[], int countPr, int countOr);


int main(void)
{
    // Make a choice for product and order
    char choice[8];
    int countPr = 0, countOr = 0;
    Item * products;
    Order * orders;


// Make a list of products and orders
    products = NULL;
    orders = NULL;

    while(1)
    {
        printf("Choose Product, Order, Print or END:  ");
        scanf(" %[^\n]s", &choice);

        // End the program
        if(!strcmp(choice, "END")) break;

        // Check the choice
        if(!strcmp(choice, "Product")) products = mkProduct(products, orders, &countPr, &countOr);
        if(!strcmp(choice, "Order")) orders = mkOrder(products, orders, &countPr, &countOr);

        // Print the product and order list
        if(!strcmp(choice, "Print")) Print(products, orders, countPr, countOr);

    }

    free(products);
    free(orders);
    return 0;
}


void Print(Item products[], Order orders[], int countPr, int countOr)
{
    int i;

    SEP;

    // Products
    for(i=0; i<countPr; i++)
    {
        printf("\nProduct #%d\n", i+1);
        printf("Name: %s\n", products[i].name);
        printf("Price: %g\n", products[i].price);
        printf("ID: %d\n", products[i].ID);
    }


    if(countOr) SEP;


    //Orders
    for(i=0; i<countOr; i++)
    {
        printf("\nOrders #%d\n", i+1);
        printf("Address: %s\n", orders[i].adress);
        printf("IDP: %d\n", orders[i].IDP);
    }


    SEP;
    NL;

}

// Product
Item *mkProduct(Item products[], Order orders[], int *countPr, int *countOr)
{
    int i,j;
    Item item;

    item = mkItem();

    /*
    // Check if it is in order
    for(i=0; i< *countOr; i++)
        if(item.ID == orders[i].IDP) {
            // remove the order
            for(j=i+1; j< *countOr; j++)
                orders[j-1] = orders[j];
            orders = (Order *)realloc(orders, --(*countOr) * sizeof(Order));

        return products;} */

    int isInOrder = rmOrder(item.ID, orders, countOr); // countOr is the pointer
    if(isInOrder) return products;

    // append the item to the item list
    products = (Item *)realloc(products, ++(*countPr) * sizeof(Item));
    if(products == NULL) exit(1);
    products[*countPr - 1] = item;

    return products;
}

// make an item
Item mkItem()
{
    Item item;

    printf("\nMake a Product:\n");
    printf("Item: ");
    scanf(" %[^\n]s", &item.name);
    printf("Price: ");
    scanf("%lf", &item.price);
    printf("ID: ");
    scanf("%d", &item.ID);
    NL;

    return item;
}

// Order
Order *mkOrder(Item products[], Order orders[], int *countPr, int *countOr)
{
    int i,j;

    Order order;
    order = mkOneOrder();

    // remove item from item list IF there is available
    int isRmv = rmProduct(order.IDP, products, countPr); // countPr is the pointer
    if(isRmv) return orders;

   // append order to the order list IF there is no available item
   orders = (Order *)realloc(orders, ++(*countOr) * sizeof(Order));
   if(orders == NULL) exit(1);
   orders[*countOr - 1] = order;

   return orders;
}

int rmProduct(int IDP, Item products[], int *countPr)
{
    int i, j;

     for(i=0; i<*countPr; i++)
        // remove item from item list IF there is available
        if(IDP == products[i].ID) {
            for(j=i+1; j<*countPr; j++)
                products[j-1] = products[j];
            if(!(*countPr - 1)) {(*countPr)--; return 1;}
            products = (Item *)realloc(products, --(*countPr) * sizeof(Item));
            if(products == NULL) exit(1);
            return 1;
       }

       return 0;
}

int rmOrder(int IDP, Order orders[], int *countOr)
{
    int i, j;

     for(i=0; i<*countOr; i++)
        // remove order from order list IF there is available
        if(IDP == orders[i].IDP) {
            for(j=i+1; j<*countOr; j++)
                orders[j-1] = orders[j];
            if(!(*countOr - 1)) {(*countOr)--; return 1;}
            orders = (Order *)realloc(orders, --(*countOr) * sizeof(Order));
           if(orders == NULL && *countOr) exit(1);
            return 1;
       }

       return 0;
}

Order mkOneOrder()
{
    Order order;

    printf("\nOrdering:\n");
    printf("Adress: ");
    scanf(" %[^\n]s", &order.adress);
    printf("ID: ");
    scanf("%d", &order.IDP);
    NL;

    return order;
}
