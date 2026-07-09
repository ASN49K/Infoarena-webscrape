#include <stdio.h>
long euclid(int a, int b)
{long c;
while (b)
{c=a%b; a=b; b=c;}
return a;}

int main()
{long a,b,t;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%ld",&t);
for(long i=1;i<=t;i++)
{scanf("%ld%ld",&a,&b);
printf("%ld\n",euclid(a,b));}
return 0;
}