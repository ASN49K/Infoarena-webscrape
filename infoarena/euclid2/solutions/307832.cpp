#include <stdio.h>
int t,a,b,r;
void readd(),solve();
int main()
{
	readd();
	solve();
	return 0;
}
void readd()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
}
void solve()
{
	for(;t;t--)
	{
		scanf("%d%d",&a,&b);
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		printf("%d\n",a);
	}
}


