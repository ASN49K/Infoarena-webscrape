#include<stdio.h>
int main
{
 int T,a,b,r;
 int i;
 *FILE f=fopen("euclid2.in","r");g=fopen("euclid2.out","w");
 fscanf("%d",&T);
 for(i=1;i<=T;i++)
  {
    fscanf("%d%d",&a,&b);
    do
     {
       r=a%b;
       a=b;
       b=r;
     }while(r!=0);
     fprintf("%d\n",a);

   return 0;
}
