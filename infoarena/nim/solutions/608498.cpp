#include<cstdio>
void read(),solve();
int t,n,a,i,S;
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%d",&t);
}
void solve()
{
	for(;t;--t)
	{
		scanf("%d",&n);
		S=0;
		for(i=1;i<=n;i++){scanf("%d",&a);S^=a;}
		S?printf("DA\n"):printf("NU\n");
	}
}