#include<stdio.h>
int a[1100],b[1100],c[1100],d[1100][1100],n,m,i,j;
int main()
{	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else
				if(d[i-1][j]>d[i][j-1])
					d[i][j]=d[i-1][j];
				else
					d[i][j]=d[i][j-1];
	printf("%d\n",d[m][n]);
	i=m;
	j=n;
	while(d[i][j])
	{
		while(d[i][j]==d[i-1][j-1])
		{
			i--;
			j--;
		}
		while(d[i][j]==d[i-1][j])
			i--;
		c[++c[0]]=a[i];
		i--;
		j--;
	}
	for(i=c[0];i;i--)
		printf("%d ",c[i]);
	return 0;
}
