#include<stdio.h>

/* Да се напише програма, която прочита от конзолата цяло число n,
въведено от потребителя, и чертае крепост с ширина 2 * n колони и
височина n реда като в примерите по-долу. Лявата и дясната колона във
 вътрешността си са широки n / 2. */


 int main(void)
 {
     int n;
     scanf("%d",&n);
     if(n>3)
     {
         /* TOP ROW */
         /* left side */
         putchar('/');
         for(int i=0;i<n/2;i++) putchar('^');
         putchar('\\');

         /* middle */
         int m = n*2 - (n/2) * 2 - 4;  /* width - 2n,  left and right sides '^' and left and right '\', '/' */
         for(int i=0; i<m;i++) putchar('_');

         /* right side */
         putchar('/');
         for(int i=0;i<n/2;i++) putchar('^');
         putchar('\\');


         /* SIDES */
         for(int i=2;i<n-1;i++)
         {
             puts(""); /* new line */
             putchar('|');
             for(int i=0; i<2*n-2; i++) putchar(' ');
             putchar('|');
         }



         /* BOTTOM ROW */

          /* middle part of the bottom row */
         puts("");
         int inMid = n/2+m/4; /* width of the internal parts of the bottom row */
         putchar('|');
         for(int i=-1;i<inMid;i++) putchar(' ');
         for(int i=0; i<m/2;i++) putchar('_');
         for(int i=-1;i<inMid;i++) putchar(' ');
         if(n%2) putchar(' ');
         putchar('|');

         puts(""); /* new line */

         /* left side */
         putchar('\\');
         for(int i=0;i<inMid;i++) putchar('_');
         putchar('/');

        for(int i=0; i<m/2;i++) putchar(' ');

         /* right side */
         putchar('\\');
         for(int i=0;i<inMid;i++) putchar('_');
         putchar('/');
     }


     return 0;
 }
