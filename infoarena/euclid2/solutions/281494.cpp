#include<stdio.h>

long cmmdc(long a, long b)
{
 long c;
 while(b)
 {
  c=a%b;
  a=b;
  b=c;
 }
 return a;
}

int main()
{
 long n,a,b;
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 scanf("%ld",&n);
 for(; n; n--)
 {
  scanf("%ld%ld",&a,&b);
  printf("%ld\n",cmmdc(a,b));
 }
 return 0;
}