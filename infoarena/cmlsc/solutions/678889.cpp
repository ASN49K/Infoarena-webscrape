#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 1024

using namespace std;

int m, n;
int a[ MAX ], b[ MAX ];

void read()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; ++i)
		scanf("%d", a + i);
	for(int i = 1; i <= n; ++i)
		scanf("%d", b + i);
}

void solve()
{
	int c[m + 1][n + 1];
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			if( a[i] == b[j] )
				c[i][j] = c[i-1][j-1] + 1;
			else
				c[i][j] = max( c[i-1][j], c[i][j-1] );
	int size = c[m][n];
	int best[ size ];
	int l = 0;
	int i = m, j = n;
	while( i && j )
		if( a[i] == b[j] )
		{
			best[l] = a[i];
			--i, --j, ++l;
		} else if( c[i-1][j] < c[i][j-1] )
			--j;
		else
			--i;

	printf("%d\n", size);
	for(int i = size - 1; i > -1; --i)
		printf("%d ", best[i]);
	printf("\n");
}

int main()
{
	read();
	solve();
	return 0;
}
