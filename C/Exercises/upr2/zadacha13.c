#include<stdio.h>
#include<math.h>

/* Учебна зала има правоъгълен размер w на h метра. Залата е разделена на две части – лява и дясна,
 с коридор приблизително по средата. В лявата и в дясната част има редици с бюра. В задната част на
  залата има голяма входна врата. В предната част на залата има катедра с подиум за преподавателя.
  Едно работно място заема 70 на 120 cm. Коридорът е широк поне 100 cm. Изчислено е, че заради входната
   врата се губи точно 1 работно място, а заради катедрата се губят точно 2 работни места.
   Напишете програма, която прочита размерите на учебната зала и изчислява броя работни места
   в нея при описаното разположение.

вход: 15 8,9   изход: 129

вход 8,4 5,2 изход: 39 */

int main(void){
    double w,h;
    double rmw = 0.7, rmh = 1.2; /* работно място 70 на 120 см */
    double countw, counth;

    printf("width: ");
    scanf("%lf",&w);
    printf("height: ");
    scanf("%lf",&h);

    w -= 1; /* коридор */
    countw = w / rmw;
    counth = h / rmh;
printf("\ncountw = %lf\tcounth = %lf\n", countw, counth);
    countw = floor(countw) - 3;
    counth = floor(counth);
printf("\ncountw = %lf\tcounth = %lf\n", countw, counth);

    double res;
    /*res = countw*counth - 1 - 2; */
    res = countw*counth;
    printf("%lf",res);

return 0;}
