#include<stdio.h>
long euclid(long a,long b)
{
long r;
while (b)
   {
     r=a%b;
     a=b;
     b=r;
   }
return a;
}

int main()
{
long t,a,b,i;

freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%ld",&t);
for (i=1;i<=t;i++)
     {
       scanf("%ld%ld",&a,&b);
       printf("%ld\n",euclid(a,b));
     }
return 0;
}