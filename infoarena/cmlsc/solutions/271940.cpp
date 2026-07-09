#include <stdio.h>
#define N 1025
int a[N][N],s[N],t[N],n,m,v[N],k;
void Read()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%d",&s[i]);
	for (int j=1; j<=m; j++)
		scanf("%d",&t[j]);
}
int max(int a,int b)
{
	if (a>b)
		return a;
	return b;
}
void Solve()
{
	Read();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			if (s[i]==t[j])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=max(a[i][j-1],a[i-1][j]);
		}
	/*for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			printf("%d ",a[i][j]);
		printf("\n");*/
	//}
	int i=n;
	int j=m;
	while (i&&j)
	{
			if (s[i]==t[j])
			{
				v[++k]=s[i];
				i--;
				j--;
			}
			else
			if (a[i][j]==a[i-1][j])
					i=i-1;
				else
					j=j-1;
		}
	printf("%d\n",a[n][m]);
	for (int i=k; i>=1; i--)
		printf("%d ",v[i]);
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	Solve();
}
