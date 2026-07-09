#include <stdio.h>
#define DIM 10024
#define max(a,b) ((a>b) ? a : b)
int a[DIM], b[DIM], d[DIM][DIM], sir[DIM], n, m, k, i, j;

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	for (i=1; i<=m; ++i)
		scanf("%d",&b[i]);
	for (i=1; i<=n; ++i)
		for ( j=1; j<=m; ++j)
			if (a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else d[i][j]=max(d[i-1][j], d[i][j-1]);
	i=n;
	j=m;
	while (i)
		if (a[i]==b[j])
			sir[++k]=a[i], --i, --j;
		else
			if (d[i-1][j]<d[i][j-1])
				--j;
			else --i;
	printf("%d\n",k);
	for (i=1; i<=k; ++i)
		printf("%d ",sir[i]);

    return 0;
}
