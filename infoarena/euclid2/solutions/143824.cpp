#include<stdio.h>
long long a,b;
int euclid(long long a, long long b)
{ if(a==b) return a;
  else if(a>b) return euclid(a-b,b);
       else return euclid(a,b-a);
}
int main()
{ freopen("euclid2.in","r",stdin);
  freopen("euclid2.out","w",stdout);
  scanf("%lld%lld",&a,&b);
  printf("%lld\n",euclid(a,b));
  fcloseall();
  return 0;
}