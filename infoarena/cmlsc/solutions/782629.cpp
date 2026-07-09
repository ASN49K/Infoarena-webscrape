#include <cstdio>
#define FOR(i,a,b) for(i=a;i<=b;i++)

int n,m,a[1025],b[1025],x[1025][1025];

void afisare (int i, int j)
{
	if (i!=0&&j!=0)
	{
		if (a[i]==b[j])
		{
			afisare (i-1,j-1);
			printf ("%d ",a[i]);
		}
		else 
		{
			if (x[i-1][j]>x[i][j-1])
				afisare (i-1,j);
			else afisare (i,j-1);
		}
	}
}

main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	int i,j;
	scanf("%d%d",&n,&m);
	
	FOR (i,1,n)
		scanf("%d",&a[i]);
	FOR (i,1,m)
		scanf("%d",&b[i]);
		
	FOR (j,1,m)
		FOR (i,1,n)
		{
			if (a[i]==b[j])
				x[i][j]=x[i-1][j-1]+1;
			else 
			{
				if (x[i-1][j]>x[i][j-1])
					x[i][j]=x[i-1][j];
				else
					x[i][j]=x[i][j-1];
			}
		}
	
	printf ("%d\n",x[n][m]);
	afisare (n,m);
}