#include <stdio.h>
long i,t,c,a,b;
int main()
{freopen("euclid.in","r",stdin);freopen("euclid.out","w",stdout);
 scanf("%ld",&t);
 for(i=1;i<=t;i++)
  {scanf("%ld%ld",&a,&b);
   while(b)
    {c=a%b;
     a=b;
     b=c;
    }
   printf("%ld\n",a);
  }
 fclose(stdin);fclose(stdout);
 return 0;
}