#include<stdio.h>
int a[1100],b[1100],d[1100][1100],i,j,n,m,c[1100];
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else
				if(d[i-1][j]>d[i][j-1])
					d[i][j]=d[i-1][j];
				else
					d[i][j]=d[i][j-1];
	printf("%d\n",d[n][m]);
	i=n;
	j=m;
	while(i>0&&j>0)
	{
		c[++c[0]]=a[i];
		i--;
		j--;
		while(d[i-1][j]==d[i][j]&&i>1)
			i--;
		while(d[i][j-1]==d[i][j]&&j>1)
			j--;
	}
	for(i=c[0];i;i--)
		printf("%d ",c[i]);
	return 0;
}

