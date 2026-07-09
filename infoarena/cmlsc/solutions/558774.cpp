#include<stdio.h>

int i,j,k,n,m,a[1025],b[1025],c[1025][1025],v[1025];

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
				c[i][j]=c[i-1][j-1]+1;
			else
			{
				if(c[i-1][j]>c[i][j-1])
					c[i][j]=c[i-1][j];
				else
					c[i][j]=c[i][j-1];
			}
			
	for(i=n,j=m;i&&j;)
	{
		if(a[i]==b[j])
		{
			k++;
			v[k]=a[i];
		}
		
		if(c[i][j-1]<c[i][j])
			i--;
		else
			j--;
	}
	
	printf("%d\n",k);
	
	for(i=k;i>=1;i--)
		printf("%d ",v[i]);
	
	return 0;
}
