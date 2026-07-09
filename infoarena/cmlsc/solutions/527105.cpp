#include<stdio.h>
#define max(a,b) ((a>b)? a:b)

int nr,q,n,m,i,j,c[1050][1050],a[1050],b[1050],d[1050];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	for (i=1;i<=m;i++)
		scanf("%d",&b[i]);
	
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
				else c[i][j]=max(c[i][j-1],c[i-1][j]);
			
	q=c[n][m];
	i=n;
	j=m;
	nr=0;
	printf("%d\n",q);

	while (i>0&&j>0)
	{
		if (a[i]==b[j])
		{
			nr++;
			d[nr]=a[i];
			i--;
			j--;
		}
		else if (c[i][j-1]<c[i-1][j]) i--;
			else j--;
	}
	for (i=nr;i>=1;i--)
		printf("%d ",d[i]);
	
	printf("\n");		
	return 0;
}