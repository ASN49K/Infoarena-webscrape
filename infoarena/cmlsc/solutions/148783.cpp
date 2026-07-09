#include <stdio.h>
#include <vector>
#define NMax 1026

int n, m;
int a[NMax], b[NMax], l[NMax][NMax];
std::vector<int> rec;

void citire();
void rez();

int main()
{
	citire();
	rez();
	return 0;
}
void rez()
{
	int i, j;

	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
		{
			l[i][j] = l[i-1][j];

			if ( l[i][j] < l[i][j-1] )
				l[i][j] = l[i][j-1];

			if ( l[i][j] < l[i-1][j-1] + 1 && a[i] == b[j] )
				l[i][j] = l[i-1][j-1] + 1;
		}

	printf( "%d\n", l[n][m] );

	i = n;
	j = m;

	while ( i > 0 && j > 0 )
	{
		if ( l[i-1][j-1]+1 == l[i][j] )
		{
			rec.push_back( a[i-1] );
			i--;
			j--;
		}
		else
		{
			if ( l[i-1][j] > l[i][j-1] )
				i--;
			else
				j--;
		}
	}

	for (i=l[n][m]-1; i>=0; i--)
		printf( "%d ", rec[i] );

}
void citire()
{
	int i, j;

	freopen( "cmlsc.in", "rt", stdin );
	freopen( "cmlsc.out", "wt", stdout );

	scanf( "%d %d", &n, &m );
	for (i=1; i<=n; i++)
		scanf( "%d", &a[i] );
	for (i=1; i<=m; i++)
		scanf( "%d", &b[i] );
}