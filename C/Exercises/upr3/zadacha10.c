#include<stdio.h>

/* ������ �� n ���� ����� � ��������� [1�1000].
 �� ��� ������� ������� p1 �� ��� 200, ���� ������� p2 �� �� 200 �� 399,
  ���� ������� p3 �� �� 400 �� 599, ���� ������� p4 �� �� 600 �� 799 �
   ���������� p5 �������� �� �� 800 ������. �� �� ������ ��������,
   ����� ��������� � ��������� ���������� p1, p2, p3, p4 � p5. */


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
