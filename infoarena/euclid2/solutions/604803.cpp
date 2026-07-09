#include<stdio.h>
long cmmdc(long a, long b)
{
	long c;
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	long n,i,a,b;
	scanf("%ld",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%ld%ld",&a,&b);
		printf("%ld\n",cmmdc(a,b));
	}
	return 0;
}