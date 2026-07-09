#include<cstdio>

int i,j,m,n,lung;

int a[1<<11],b[1<<11];

int c[1<<11][1<<11];

int s[1<<11];


inline int max(int x,int y)
{
	if (x>y) return x;
	return y;
}


int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d%d", &n,&m);
		
	for(i=1;i<=n;i++)
		scanf("%d", &a[i]);
	for (j=1;j<=m;j++)
		scanf("%d", &b[j]);
	
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			if ( a[i]==b[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				continue;
			}
			
			c[i][j]=max(c[i][j-1],c[i-1][j]);
			
		}
	
	for (i=n,j=m;i;)
	{
		if (a[i]==b[j])
		{
			s[++lung]=a[i];
			--i;--j;
		}
		
		if ( c[i-1][j] > c[i][j-1]) i--;
		else j--;
		
	}
	
	printf("%d\n" , lung);

	for (i=1;i<=lung;i++)
		printf("%d ", s[lung-i+1]);
	
	return 0;
}


