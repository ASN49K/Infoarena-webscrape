#include<stdio.h>

long long a,b;
int t;

int main()
{	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{	scanf("%lld%lld",&a,&b);
		long long r;
		while(a%b)
		{	r=a%b;
			a=b;
			b=r;
		}
		printf("%lld\n",b);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
