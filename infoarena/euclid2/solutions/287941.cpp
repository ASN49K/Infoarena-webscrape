#include<stdio.h>
void readd(),solve();
int T,a,b,cmmdc(int mare, int mic);
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
	scanf("%d",&T);
}
void solve()
{
		for(;T;T--)
		{
				scanf("%d%d",&a,&b);
				printf("%d\n",cmmdc(a,b));
		}
}
int cmmdc(int mare, int mic)
{
		int rest;
		while(mic)
		{
				rest=mare%mic;mare=mic;mic=rest;
		}
		return mare;
}