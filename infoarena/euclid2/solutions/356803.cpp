#include<stdio.h>
int t,a,r,b;
void read(), solve();
int main()
{
	read();
	solve();
	return 0;
}
void read()
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
	