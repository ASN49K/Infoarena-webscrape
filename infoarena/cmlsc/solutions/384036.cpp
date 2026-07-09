#include<stdio.h>

const int N=1050;

int n,m,x[N],y[N],v[N][N],rez[N],pz;
bool px[N][N],py[N][N];

void read()
{
	scanf("%d%d",&n,&m);
	for( int i=1 ; i<=n ; ++i )
		scanf("%d",&x[i]);
	for( int i=1 ; i<=m ; ++i )
		scanf("%d",&y[i]);
}

void solve()
{
	for( int i=1 ; i<=n ; ++i )
		for( int j=1 ; j<=m ; ++j )
			if( x[i]==y[j] )
			{
				v[i][j]=v[i-1][j-1]+1;
				px[i][j]=py[i][j]=1;
			}
			else
			{
				if( v[i-1][j]>v[i][j-1] )
				{
					v[i][j]=v[i-1][j];
					px[i][j]=1;
					py[i][j]=0;
				}
				else
				{
					v[i][j]=v[i][j-1];
					px[i][j]=0;
					py[i][j]=1;
				}
			}
}

void print()
{
	printf("%d\n",v[n][m]);
	int i=n,j=m;
	while( i>=1 && j>=1 )
	{
		if(px[i][j]==1 && py[i][j]==1)
		{
			rez[++pz]=x[i];
			--i;
			--j;
		}
		else if(px[i][j]==1&&py[i][j]==0)
			--i;
		else
			--j;
	}
	while(pz>=1)
		printf("%d ",rez[pz--]);
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	read();
	solve();
	print();
	return 0;
}
