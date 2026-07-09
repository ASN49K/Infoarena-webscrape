#include<stdio.h>
long a,b,n;

long cmmdc(long a,long b)
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

void read()
{
	scanf("%ld",&n);
	long i;
	for (i=1;i<=n;i++)
	{
		scanf("%ld%ld",&a,&b);
		printf("%ld\n",cmmdc(a,b));
	}
}


int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
read();
return 0;
}
