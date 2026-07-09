#include<cstdio>
int main()
{
	int a[1030],b[1030],c[1030][1030],d[1030];

	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int i,j,k,m,n;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				if(c[i-1][j]<c[i][j-1])
					c[i][j]=c[i][j-1];
				else
					c[i][j]=c[i-1][j];
			
	printf("%d\n",c[m][n]);
	i=m;j=n;
	k=0;
	while(i>=1)
	{
		if(a[i]==b[j])
		{	k++;
			d[k]=a[i];
			i--;
			j--;
		}
		else
			if(c[i-1][j]<c[i][j-1])
				j--;
			else
				i--;
	}
	for(i=k;i>=1;i--)
		printf("%d ",d[i]);
		
	
return 0;
}

