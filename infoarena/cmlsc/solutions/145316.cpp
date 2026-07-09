#include <stdio.h>

int n,m,a[1024],b[1024],d[1024][1024],c[1024],z;

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j;
	for (i=1; i<=n; ++i) scanf("%d",&a[i]);
	for (i=1; i<=m; ++i) scanf("%d",&b[i]);
	for (i=1; i<=n; ++i)
	{
		for (j=1; j<=m; ++j)
		{
			d[i][j]=d[i-1][j-1];
			if (d[i][j-1]>d[i][j]) d[i][j]=d[i][j-1];
			if (d[i-1][j]>d[i][j]) d[i][j]=d[i-1][j];
			if (a[i]==b[j] && d[i-1][j-1]+1>d[i][j]) 
			{
				d[i][j]=d[i-1][j-1]+1;
				c[++z]=a[i];
			}
		}
	}
	printf("%d\n",d[n][m]);
	for (i=1; i<=z; ++i) printf("%d ",c[i]);
	return 0;
}