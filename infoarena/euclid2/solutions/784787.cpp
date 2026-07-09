#include<cstdio>
#define ll long long
ll euclid(ll a,ll b)
{
	if(!b)return a;
	else euclid(b,a%b);
	
}
/*
ll euclid2(ll a,ll b)
{
	while(a*b)
	{
		a>b? a%=b : b%=a;
	}
	return a+b;
}
*/
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int t;

	ll a,b,rez;
	
	scanf("%d",&t);

	for(int i=1;i<=t;++i)
	{
	scanf("%lld %lld ",&a,&b);	
	printf("%lld\n",euclid(a,b));
	}

	return 0;
}