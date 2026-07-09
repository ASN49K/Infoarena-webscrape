#include<stdio.h>
long long T,a,b;
long long euclid(long long a,long long b)
{ if(b==0) return a;
  else return euclid(b,a%b);
}
int main()
{ freopen("euclid2.in","r",stdin);
  freopen("euclid2.out","w",stdout);
  scanf("%lld",&T);
  long long i;
  for(i=1;i<=T;i++)
     { scanf("%lld%lld",&a,&b);
       printf("%lld\n",euclid(a,b));
     }
  return 0;
}
