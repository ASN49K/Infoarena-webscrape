#include<stdio.h>

long long a,b,aux;

void solve()
{if(a<b) a^=b^=a^=b;
 while(b!=0)
  {aux=a%b;
   a=b;
   b=aux;
  }
 printf("%lld\n",a);
}

int main()
{
 long n;
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 scanf("%ld",&n);
 for(int i=1;i<=n;i++)
    {scanf("%lld %lld",&a,&b);
     solve();
    }
return 0;
}
