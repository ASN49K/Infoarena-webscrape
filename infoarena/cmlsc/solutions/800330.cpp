#include<stdio.h>
int i,j,k,v[2000],w[2000],a[1050][1050],q,m,n,l,h[1050];
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(v[i]==w[j])
				a[i][j]=1+a[i-1][j-1];
			else
				if(a[i][j-1]>a[i-1][j])
					a[i][j]=a[i][j-1];
				else
					a[i][j]=a[i-1][j];
		}
	}
	i=n;
	j=m;
	while(i>0&&j>0)
	{
		if(v[i]==w[j])
		{
			h[++q]=v[i];
			i--;
			j--;
		}
		else
			if(a[i-1][j]>a[i][j-1])
				i--;
			else
				j--;
			}
	printf("%d\n",a[n][m]);
	for(i=q;i>=1;i--)
	{
		printf("%d ",h[i]);
	}
	
	return 0;
}
	