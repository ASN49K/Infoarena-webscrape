#include<stdio.h>
int main
{
 int T,a,b,r;
 int i;
 *FILE f=fopen("euclid2.in","r");g=fopen("euclid2.out","w");
 scanf("%d",&T);
 for(i=1;i<=T;i++)
  {
    scanf("%d%d",&a,&b);
    do
     {
       r=a%b;
       a=b;
       b=r;
     }while(r!=0);
     printf("%d\n",a);

   return 0;
}
