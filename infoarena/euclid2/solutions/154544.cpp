#include <stdio.h>
long long a,b,d,t;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	scanf("%d",&t);

	for(;t>0;t--)
	{
	scanf("%lld %lld",&a,&b);

	while(a!=0&&b!=0)
	{
		if(a>b)
			a=a%b;
		else
			b=b%a;
	}
	if(a==0)
		printf("%lld\n",b);
	else
		printf("%lld\n",a);
	}
	return 0;

}