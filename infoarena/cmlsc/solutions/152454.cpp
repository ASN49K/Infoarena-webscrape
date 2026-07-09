#include<stdio.h>
#define NMAX 1051
long x[NMAX],rez[NMAX],y[NMAX],z[NMAX][NMAX],i,j,n,m,k,l,a,s;
long max(long a,long b)
{
	if (a>b) return a;
	return b;
}

long min(long a,long b)
{
	if (a<b) return a;
	return b;
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%ld",&x[i]);
	for (i=1;i<=m;i++)
		scanf("%ld",&y[i]);

	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (x[i]==y[j])
				z[i][j]=z[i-1][j-1]+1;
			else
				z[i][j]=max(z[i-1][j],z[i][j-1]);
	printf("%ld\n",z[n][m]);
	i=n;
	j=m;
	while (i&&j)
	{
		if (x[i]==y[j])
		{
			rez[++rez[0]]=x[i];
			i--;
			j--;
		}
		else
		if (z[i-1][j]<z[i][j-1])
			j--;
		else
			i--;
	}
	for (i=rez[0];i>=1;i--)
		printf("%ld ",rez[i]);
	printf("\n");

	return 0;
}