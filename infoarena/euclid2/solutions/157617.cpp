#include<stdio.h>
long long a,b,r;
int t,i;
int main()
{freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 scanf("%d",&t);
 for(i=1;i<=t;i++)
  {scanf("%lld %lld",&a,&b);
   if(a<b)
    {r=a;
     a=b;
     b=r;
     r=0;
    }
   while(b!=0)
    {r=b;
     b=a%r;
     a=r;
    }

   printf("%lld",a);
  }
return 0;
}
