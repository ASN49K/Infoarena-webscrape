#include<iostream.h>
#include <stdlib.h>

int main()
{
    int a,b,i,x,r;
   freopen("euclid2.in", "r",stdin);
    freopen("euclid2.out", "w",stdout);
    scanf("%d",&x); 
 for(i=1;i<=x;i++)
 {
  scanf("%d",&a);
scanf("%d",&b);
while(a%b!=0)
 {
  r=a%b;
  a=b;
  b=r;
 }
printf("%d\n",b);
 }
return 0;
}          
