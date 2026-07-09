#include <cstdio>
int n,m,a[1025],b[1025],q,i,j,x[1025][1025],v[1025];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (i=1;i<=m;++i)
	{
		scanf("%d",&b[i]); 
		for (j=1;j<=n;++j)
			if (a[j]==b[i])
				x[i][j]=x[i-1][j-1]+1; else
					if (x[i-1][j]>x[i][j-1]) 
						x[i][j]=x[i-1][j]; else
							x[i][j]=x[i][j-1];
	}
	
	q=x[m][n];
	printf("%d\n",q);
	
	for (i=q;i>0;--i)
		{
			while (b[m]!=a[n]) 
				if (x[m-1][n]>x[m][n-1])
					--m; else --n;
			v[i]=b[m];
			--m;--n;		
	     }
	for (i=1;i<=q;++i)
		printf("%d ",v[i]);
	return 0;}	
			
			
	
	
				
	
		
	