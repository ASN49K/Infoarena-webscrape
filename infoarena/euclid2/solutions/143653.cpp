#include<stdio.h>
long a,b,r;
int main()
{
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 scanf("%ld%ld",&a,&b);
 while(b)
  {r=a%b;
   a=b;
   b=r;
  }
 printf("%ld",a);
 return 0;
}