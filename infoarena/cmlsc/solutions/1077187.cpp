#include <fstream>
using namespace std;
ifstream cin( "cmlsc.in" );
ofstream cout( "cmlsc.out" );

int n, m, a[ 1025 ], b[ 1025 ], ultim, c[ 1025 ];
int main()
{
	int i, j;
	cin >> n >> m;
	for ( i = 1; i <= n; i++ )
		cin >> a[ i ];
	for ( j = 1; j <= m; j++ )
		cin >> b[ j ];
	ultim = 1;
	for ( i = 1; i <= n; i++ )
		for ( j = ultim; j <= m; j++ )
			if ( a[ i ] == b[ j ] )
			{
				c[ ++c[ 0 ] ] = a[ i ];
				ultim = j + 1;
				break;
			}
	cout << c[ 0 ] << '\n';
	for ( i = 1; i <= c[ 0 ]; i++ )
		cout << c[ i ] << " ";
}