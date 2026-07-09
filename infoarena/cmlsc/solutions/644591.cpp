#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int n,m,nr;
int a[1031],b[1031],v[1031];
int d[1031][1031];

void read()
{
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=m;++i)
		scanf("%d",&b[i]);
}

void dp()
{
	int i,j;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else d[i][j]=max(d[i][j-1],d[i-1][j]);
		}
}

void sol()
{
	int i,j;
	i=n; j=m; nr=0;
	while(i>0 && j>0 && d[i][j]>0)
	{
		if(a[i]==b[j])
		{
			nr++;
			v[nr]=a[i];
			--i;
			--j;
		}
		else if(d[i][j-1]<=d[i-1][j])
			i--;
		else j--;
	}
}

void write()
{
	int i;
	printf("%d\n",d[n][m]);
	for(i=nr;i>=1;--i)
		printf("%d ",v[i]);
}

int main()
{
	read();
	dp();
	sol();
	write();
	return 0;
}