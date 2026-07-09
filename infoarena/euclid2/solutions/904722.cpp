#include<cstdio>
#define LL long long
int t,i,j;
LL a,b,r;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		scanf("%lld %lld",&a,&b);
		r=a%b;
		while (r) a=b,b=r,r=a%b;
		printf("%lld\n",b);
	}
	return 0;
}