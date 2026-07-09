#include<stdio.h>
int i,j,k,v[2000],w[2000],a[2000],q,m,n,l;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&w[i]);
	l=1;
	for(i=1;i<=n;i++)
	{
		for(j=l;j<=m;j++)
		{
			if(v[i]==w[j])
			{
				k++;
				l=j+1;
				a[++q]=v[i];
		}
	}
	}
	printf("%d\n",k);
	for(i=1;i<=q;i++)
		printf("%d ",a[i]);
	return 0;
}
	