#include<stdio.h>
int main()
{
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
  int aux,a,b,i;


      scanf("%d",&a);
      scanf("%d",&b);


    while(b!=0)
     {
       aux = b;
       b = a%b;
       a = aux;


     }
  printf("%d",a);
  printf("\n");

 return 0;
}
