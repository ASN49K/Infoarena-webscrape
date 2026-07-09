#include<stdio.h>
#include<stdlib.h>
long long a,b;
long long euclid(long long a, long long b)
{ if(!b) return a;
  else return euclid(b,a%b);
}
int main()
{ freopen("euclid2.in","r",stdin);
  freopen("euclid2.out","w",stdout);
  scanf("%lld%lld",&a,&b);
  printf("%lld\n",euclid(a,b));
  fcloseall();
  return 0;
}