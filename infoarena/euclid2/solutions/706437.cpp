#include <cstdio>

long euclid(long a,long b)
{
	long r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	
	return b;
}

int main()
{
	freopen("euclid2.in","rt",stdin);
	freopen("euclid2.out","wt",stdout);
	
	long a,b,n;

	scanf("%ld",&n);
	for(long i=1;i<=n;i++)
	{
		scanf("%ld %ld",&a,&b);
		euclid(a,b);
	}

	printf("%ld\n",b);

	return 0;
}