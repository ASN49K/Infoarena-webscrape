#include<stdio.h>
int main()
{
 int T,a,b,r,i;
 freopen("euclid2.in","r",stdin);
 freopne("euclid2.out","w",stdout);
 scanf("%d",&T);
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
