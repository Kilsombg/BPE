#include<stdio.h>
#include<math.h>

/* По дадени координатите на три точки, не лежащи на една права, намерете лицето на триъгълника, формиран от тях.  */

int main(void)
{
    int Ax,Ay,Bx,By,Cx,Cy;
    scanf("%d %d",&Ax,&Ay);
    scanf("%d %d",&Bx,&By);
    scanf("%d %d",&Cx,&Cy);

    double a,b,c;
    a = sqrt((double)((Ax-Bx)*(Ax-Bx) + (Ay-By)*(Ay-By)));
    b = sqrt((double)((Bx-Cx)*(Bx-Cx) + (By-Cy)*(By-Cy)));
    c = sqrt((double)((Cx-Ax)*(Cx-Ax) + (Cy-Ay)*(Cy-Ay)));

    double p = (a+b+c)/2.;
    double S = (sqrt(p*(p-a)*(p-b)*(p-c)));

    printf("S = %lf",S);


    return 0;
}
