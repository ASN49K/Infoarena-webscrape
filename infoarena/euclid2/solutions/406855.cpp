#include<stdio.h>

long cmmdc(long a,long b)
{	long r;
	while (a%b!=0)
	{	r=a%b;
		a=b;
		b=r;
	}
	return b;
}

int main()
{	long a,b,t;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&t);
	for (;t;t--)
	{	scanf("%ld%ld",&a,&b);
		printf("%ld\n",cmmdc(a,b));
	}
	return 0;
}
