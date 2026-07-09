#include <stdio.h>

int d[1025], a[1025], b[1025];
int c[1025][1025];
int i,j,n,m,nr;

inline int max(int x, int y)
{
	if (x>y) return x;
	return y;
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (i=1; i<=m; i++)
		scanf("%d",&b[i]);
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			if (a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
	i=n; j=m; nr=0;
	while (i>=1 && j>=1)
	{
		if (a[i]==b[j])
		{
			d[++nr]=a[i];
			i--; j--;
		}
		else
			if (c[i-1][j]>c[i][j-1]) i--;
			else j--;
	}
	printf("%d\n",c[n][m]);
	for (i=nr; i>=1; i--)
		printf("%d ",d[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}