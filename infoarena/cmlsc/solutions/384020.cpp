#include<stdio.h>

const int N=1050;

int n,m,x[N],y[N],v[N][N],pred[N][N];

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
				pred[i][j]=1;
			}
			else
			{
				if( v[i-1][j]>v[i][j-1] )
				{
					v[i][j]=v[i-1][j];
					pred[i][j]=-1;
				}
				else
				{
					v[i][j]=v[i][j-1];
					pred[i][j]=0;
				}
			}
}

void rec( int i,int j )
{
	if( i<=1 && j<=1 )
	{
		if(pred[1][1]==1)
			printf("%d ",x[1]);
		return;
	}
	if( pred[i][j]==-1 )
		rec(i-1,j);
	else if( pred[i][j]==0 )
		rec(i,j-1);
	else
	{
		rec(i-1,j-1);
		printf("%d ",x[i]);
	}
}

void afff()
{
	for( int i=1 ; i<=n ; ++i,printf("\n") )
		for( int j=1 ; j<=n ; ++j )
		{
			if( pred[i][j]==-1 )
				printf(" ^");
			else if( pred[i][j]==0 )
				printf(" <");
			else
				printf(" x");
			printf("%3d",v[i][j]);
		}
}

void print()
{
	printf("%d\n",v[n][m]);
	//afff();
	rec(n,m);
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
