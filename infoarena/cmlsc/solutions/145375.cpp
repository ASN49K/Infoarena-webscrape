#include <stdio.h>

int n,m,a[1024],b[1024],c[1024],z,q;
char d[1024][1024],e[1024][1024];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	int i,j;
	for (i=1; i<=n; ++i) scanf("%d",&a[i]);
	for (i=1; i<=m; ++i) scanf("%d",&b[i]);
	for (i=0; i<=n; ++i) 
		for (j=0; j<=m; ++j) d[i][j]=0;
	for (i=1; i<=n; ++i)
	{
		for (j=1; j<=m; ++j)
		{
			q=1;
			d[i][j]=d[i-1][j-1];
			if (d[i][j-1]>d[i][j]) 
			{
				d[i][j]=d[i][j-1];
				q=2;
			}
			if (d[i-1][j]>d[i][j]) 
			{
				d[i][j]=d[i-1][j];
				q=3;
			}
			if (a[i]==b[j] && d[i-1][j-1]+1>=d[i][j]) 
			{
				d[i][j]=d[i-1][j-1]+1;
				q=1;
			}
			e[i][j]=q;

		}
	}
	printf("%d\n",d[n][m]);
	i=n;
	j=m;
	z=0;
	while (e[i][j]!=0)
	{
		if (a[i]==b[j])
		{
			c[++z]=a[i];
		}
		if (e[i][j]==1)
		{
			i-=1;
			j-=1;
			continue;
		}
		if (e[i][j]==2)
		{
			j-=1;
			continue;
		}
		if (e[i][j]==3) i-=1;
	}
	for (i=z; i>0; --i) printf("%d ",c[i]);
	return 0;
}