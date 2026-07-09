#include<stdio.h>
long  T,a,b;
long cmmdc(long a,long b)
   {long r=a%b;
    while(r)
         {
          r=a%b;
          a=b;
          b=r;
         }
    return a;
    }
void main()
   { freopen("euclid2.in","r",stdin); freopen("euclid2.out","w",stdout);
    scanf("%ld",&T);
    for(long i=1;i<=T;i++)
       {scanf("%ld %ld",&a,&b);
        if(a>b) a+=b,b=a-b,a-=b;
        printf("%ld\n",cmmdc(a,b));
        }
    }
