#include<cstdio>

using namespace std;
int n,m,j,i,a[1050],b[1050],v[1050][1050],sol[1050],nr,max;
void read(),solve();
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
}
void solve()
{
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=(v[i-1][j]>v[i][j-1])?v[i-1][j]:v[i][j-1];
	max=v[n][m];
	printf("%d\n",max);
	i=n;j=m;nr=max;
	for(;max;)
	{
		if(v[i-1][j]==max)
		{
			i--;
			continue;
		}
		if(v[i][j-1]==max)
		{
			j--;
			continue;
		}
		sol[max]=a[i];i--;j--;max--;
	}
	for(i=1;i<=nr;i++)
		printf("%d ",sol[i]);
}