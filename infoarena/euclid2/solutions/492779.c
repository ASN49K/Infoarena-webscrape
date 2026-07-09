#include<stdio.h>
int main
{
 int T,a,b;
 int i;
 *FILE f=fopen("euclid2.in","r");g=fopen("euclid2.out","w");
 scanf("%d",&T);
 for(i=1;i<=T;i++)
  {
    scanf("%d%d",&a,&b);
    while(b>0)
     {
       r=a%b;
       a=b;
       b=r;
     }
     printf("%d\n",a);

   return 0;
}
