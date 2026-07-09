#include <stdio.h>

int i,j,n,m,a[1026],b[1026],mx[1026][1026],nr;

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j]) mx[i][j]=mx[i-1][j-1]+1;
			else
			if(mx[i-1][j]>mx[i][j-1]) mx[i][j]=mx[i-1][j];
			else
			mx[i][j]=mx[i][j-1];

	printf("%d\n",mx[n][m]);
	i=n;
	j=m;
	nr=mx[n][m];
	while(i!=0&&j!=0&&nr!=0)
	{
		while(mx[i][j-1]==nr) j--;
		while(mx[i-1][j]==nr) i--;
		nr--;
		printf("%d ",b[j]);
		i--;
		j--;
	}
	printf("\n");

	return 0;
}
