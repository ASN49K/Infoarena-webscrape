#include <fstream>
#include <algorithm>
using namespace std;

int a[150];
int b[150];
int c[256][256];
int m, n, i, j;
void Scrie(int i, int j);

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
	
	fin >> n >> m;
	for ( i = 1; i <= n; ++i)
		fin >> a[i];
	for ( j = 1; j <= m; ++j) 
		fin >> b[j];
	
	for ( i = 1; i <= n; ++i )
		for ( j = 1; j <= m; ++j)
			if ( a[i] == b[j] )
				c[i][j] = 1 + c[i-1][j-1];
			else
				c[i][j] = max( c[i-1][j], c[i][j-1] );
	
	fout << c[n][m] << '\n';
	Scrie(n, m );
	fin.close();
	fout.close();
	return 0;
}

void Scrie( int i, int j)
{
	if ( i == 0 || j == 0 )
		return;
	if ( a[i] == b[j] )
	{
		Scrie( i-1, j-1 );
		fout << a[i] << ' ';
	}
	else
		if ( c[i-1][j] > c[i][j-1] )
			Scrie( i - 1, j );
		else
			Scrie( i, j - 1);
}