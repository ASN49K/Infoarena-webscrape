#include <cstdio>
int a[1030],b[1030],sir[1030];
int n,m;
int lung[1030][1030];

int max(int a,int b)
{
	if (a>b)
		return a;
	return b;
}

void citire()
{
	freopen ("cmlsc.in","r",stdin);
	freopen ("cmlsc.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (i=1;i<=m;++i)
		scanf("%d",&b[i]);
}

void dinamica()
{
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if (a[i]==b[j])
				lung[i][j]=1+lung[i-1][j-1];
			else
				lung[i][j]=max(lung[i-1][j],lung[i][j-1]);
}

void scrie()
{
	printf("%d\n",lung[n][m]);
	int k=0,i=n,j=m;
	while (i&&j)
	{
		if (a[i]==b[j])
		{
			sir[++k]=a[i];
			--i;
			--j;
		}
		else
			if (lung[i-1][j]>lung[i][j-1])
				--i;
			else
				--j;
	}
	for (int i=k;i;--i)
		printf("%d ",sir[i]);
	printf("\n");
}

int main()
{
	citire();
	dinamica();
	scrie();
	return 0;
}
