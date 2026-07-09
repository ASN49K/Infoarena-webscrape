#include<stdio.h>
#define N 1030
int m,n,s[N],t[N],a[N][N],v[N];
void citire()
{
	int i;
	scanf("%d",&m);
	scanf("%d",&n);
	for(i=1;i<=m;++i)
		scanf("%d",&s[i]);
	for(i=1;i<=n;++i)
		scanf("%d",&t[i]);
}
int max(int x,int y)
{
	if(x>y)
		return x;
	return y;
}
void solve()
{
	int j,i,k=0;
	citire();
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			if(s[i]==t[j])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=max(a[i-1][j],a[i][j-1]);

	printf("%d\n",a[m][n]);
	i=m;
	j=n;
	while(i&&j)
	{
		if(s[i]==t[j])
		{
			v[++k]=s[i];
			--i;
			--j;
		}
		else
			if(a[i][j]==a[i-1][j])
				--i;
			else
				--j;
	}
	for(i=k;i;--i)
		printf("%d ",v[i]);
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	solve();
	return 0;
}