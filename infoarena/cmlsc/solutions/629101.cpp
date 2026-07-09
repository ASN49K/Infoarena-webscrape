#include <cstdio>
int d[1025][1025];
int main()
{
	int a[1025],b[1025],n,m,i,j,max,max2,poz;
	
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (i=n;i>0;--i)
		scanf("%d",&a[i]);
	for (i=m;i>0;--i)
		scanf("%d",&b[i]);
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
			if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1; else
				if (d[i][j-1]>d[i-1][j]) 
					d[i][j]=d[i][j-1]; else
						d[i][j]=d[i-1][j];
	printf("%d\n",d[n][m]);
	i=n;j=m;
	while (d[n][m])
	{
		if (a[i]==b[j]) {printf("%d ",a[i]);--i;--j;--d[n][m];} else
			if (d[i-1][j]>d[i][j-1]) --i; else
				--j;
	}
return 0;
}
				
		
		
				
		
	