#include<stdio.h>
long long Euclid(long long a,long long b)
{
	long long r;
	if(b>a)
	{
		r=a;
		a=b;
		b=r;
	}
	do
	{
		r=a%b;
		a=b;
		b=r;
	}
	while(b);
	return a;
}	
int main()
{
	long long a=0,b=0;
	int t;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d\n",&t);
	while(t)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",Euclid(a,b));
		--t;
	}
	return 0;
}