#include <stdio.h>
#include <vector>
#define NMax 1025

int n, m;
int a[NMax], b[NMax];
std::vector<int> c;

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
	int i, j, starty, lg;


	starty = 0;

	for (i=0; i<n; i++)
	{
		for (j=starty; j<m; j++)
		{
			if ( a[i] == b[j] )
			{
				c.push_back( a[i] );
				starty = j+1;
				break;
			}
		}
	}

	lg = c.size();
	printf( "%d\n", lg );
	for (i=0; i<lg; i++)
		printf( "%d ", c[i] );
}
void citire()
{
	int i, j;

	freopen( "cmlsc.in", "rt", stdin );
	freopen( "cmlsc.out", "wt", stdout );

	scanf( "%d %d", &n, &m );
	for (i=0; i<n; i++)
		scanf( "%d", &a[i] );
	for (i=0; i<m; i++)
		scanf( "%d", &b[i] );
}