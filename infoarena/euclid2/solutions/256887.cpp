#include<stdio.h>
long t,i,a,b;
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout); 
 
 scanf("%ld",&t);
 for(i=1;i<=t;++i)
 {
  scanf("%ld%ld",&a,&b);
  while(a!=b)
  {if(a>b) a-=b;
   else b=b-a;
   } 
   printf("%ld\n",b);
 }
return 0;
}
