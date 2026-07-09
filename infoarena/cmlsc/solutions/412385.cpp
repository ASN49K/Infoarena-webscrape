#include <fstream>
#define DIM 200
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[DIM], b[DIM],c[DIM][DIM];
void Write( int i, int j );

int main()
{
	int n, m;
	fin >> n >> m;
	for ( int i = 1; i <= n; ++i )
		fin >> a[i];
	for ( int j = 1; j <= m; ++j )
		fin >> b[j];
	
	for ( int i = 1; i <= n; ++i )
		for ( int j = 1; j <= m; ++j )
			if ( a[i] == b[j] )
				c[i][j] = c[i-1][j-1] + 1;
			else
				c[i][j] = max ( c[i-1][j], c[i][j-1] );
			
	fout << c[n][m] << '\n';
	Write( n, m );
	return 0;
}

void Write( int i, int j )
{
	if(  i == 0 || j == 0 )
		return;
	if(  a[i] == b[j] )
	{
		Write( i-1, j-1 ); 
		fout << a[i] << ' ';
	}
	else 
		if ( c[i-1][j] > c[i][j-1] )
			Write(i-1, j);
		else
			Write(i, j-1 );
}