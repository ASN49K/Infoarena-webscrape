#include<cstdio>
using namespace std;

int maxim (int x,int y)
{
	if (x>=y) return x;
	return y;
}

int a[1030],b[1030],c[1030][1030],sol[1030];

int main ()
{
	int m,n,i,j,ka,nr;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (i=1; i<=m; i++)
		scanf("%d",&a[i]);
	for (i=1; i<=n; i++)
		scanf("%d",&b[i]);
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
		{
			if (a[i]==b[j]) 
				c[i][j]=c[i-1][j-1]+1;
			else c[i][j]=maxim(c[i-1][j],c[i][j-1]);
		}
	printf("%d\n",c[m][n]);
	ka=0; i=m; j=n; nr=c[m][n];
	while (i)
	{
		if (a[i]==b[j] && nr) 
		{
			sol[++ka]=a[i];
			i--; j--; nr--;
		}
		else if (c[i][j-1]==nr)
			j--;
		else i--;
	}
	for (i=ka; i>=1; i--)
		printf("%d ",sol[i]);
	return 0;
}
