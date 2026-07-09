#include<stdio.h>

int d[1024][1024],i,j,m,n,l,a[1024],b[1024];


void afiseaza(int i,int j)
{
	if(!d[i][j]) return;

	if(a[i]==b[j])
	{
		afiseaza(i-1,j-1);
		printf("%d ",a[i]);
		return;
	}
	if(d[i][j]==d[i-1][j])
	{
		afiseaza(i-1,j);
		return;
	}
	afiseaza(i,j-1);
	return;
}

int main(void)
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++)
	{
			scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			d[i][j]=(d[i-1][j]>d[i][j-1])?d[i-1][j]:d[i][j-1];

			if(a[i]==b[j] && d[i][j]<d[i-1][j-1]+1)
			{
				d[i][j]=d[i-1][j-1]+1;
			}

		}
	}
	l=d[n][m];
	printf("%d\n",l);

	afiseaza(n,m);

	return 0;
}

