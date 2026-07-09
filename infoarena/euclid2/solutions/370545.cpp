#include<iostream.h>
#include <stdlib.h>

int main()
{
    int a,b,i,x;
   freopen("euclid2.in", "r",stdin);
    freopen("euclid2.out", "w",stdout);
    scanf("%d",&x); 
 for(i=1;i<=x;i++)
 {
  scanf("%d",&a);
scanf("%d",&b);
while((a!=b)&&(a!=0)&&(b!=0))
 {
  if(a>b)
  a=a%b;
  else
  b=b%a;
}  
printf("%d\n",b);
}
return 0;
}          
