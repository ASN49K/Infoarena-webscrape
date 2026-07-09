#include <stdio.h>

int i,j,n,m,a[1026],b[1026],mx[1026][1026],nr,v[1026],w;

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
	w=0;
	while(i!=0&&j!=0&&nr!=0)
	{
		while(mx[i][j-1]==nr) j--;
		while(mx[i-1][j]==nr) i--;
		nr--;
		v[++w]=b[j];
		i--;
		j--;
	}
	for(i=w;i>1;i--)
		printf("%d ",v[i]);
	printf("%d\n",v[1]);

	return 0;
}
