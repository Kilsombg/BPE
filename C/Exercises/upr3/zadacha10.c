#include<stdio.h>

/* Дадени са n цели числа в интервала [1…1000].
 От тях някакъв процент p1 са под 200, друг процент p2 са от 200 до 399,
  друг процент p3 са от 400 до 599, друг процент p4 са от 600 до 799 и
   останалите p5 процента са от 800 нагоре. Да се напише програма,
   която изчислява и отпечатва процентите p1, p2, p3, p4 и p5. */


   int main(void)
   {
       int n, c1,c2,c3,c4,c5;
       c1=c2=c3=c4=c5=0;
       int x;
       puts("n=");
       scanf("%d",&n);

       for(int i=0;i<n;i++)
       {
           puts("x = ");
           scanf("%d",&x);

            if(x<200) c1++;
            else if(x<=399) c2++;
                else if(x<=599) c3++;
                    else if(x<=799) c4++;
                        else c5++;
       }

       printf("p1 = %g", (double)c1*100/n);
       printf("p1 = %g", (double)c2*100/n);
       printf("p1 = %g", (double)c3*100/n);
       printf("p1 = %g", (double)c4*100/n);
       printf("p1 = %g", (double)c5*100/n);
       return 0;
   }
