#include<stdio.h>
#define N 1026
int n,m,v[N],v1[N],v2[N],a[N][N];
void citire()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&v1[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&v2[i]);
}
void matrice()
{
	for (int i=1; i<=n; ++i)
	{
		for (int j=1; j<=m; ++j)
			if (v1[i]==v2[j])
				a[i][j]=a[i-1][j-1]+1;
			else
				if (a[i-1][j]>a[i][j-1])
					a[i][j]=a[i-1][j];
				else
					a[i][j]=a[i][j-1];
	}
	printf("%d\n",a[n][m]);
}
void sir()
{
	int i=n,j=m,nr=a[n][m];
	while (a[i][j])
	{
		if (v1[i]==v2[j])
		{
			v[nr--]=v1[i];
			--i;
			--j;
		}
		else
			if (a[i-1][j]>a[i][j-1])
				--i;
			else
				--j;
	}
	for (int i=1; i<=a[n][m]; ++i)
		printf("%d ",v[i]);
}
int main()
{
	citire();
	matrice();
	sir();
	return 0;
}
