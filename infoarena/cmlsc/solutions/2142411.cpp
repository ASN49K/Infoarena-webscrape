#include <fstream>

#define N 1025

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n,m,x,i,j,a[N],b[N],v[N],d[N][N];

void printSol ( int i, int j )
{
	if ( !i )
		return;

	if ( b[i] == a[j] )
		printSol (i-1, j-1), fout << b[i] << " ";

	else if ( d[i-1][j] < d[i][j-1] )
		printSol (i, j-1);

	else
		printSol (i-1, j);
}

int main()
{
	fin >> n >> m;

	for ( i = 1; i <= n; ++i )
		fin >> a[i];

	for ( i = 1; i <= m; ++i )
	{
		fin >> b[i];

		for ( j = 1; j <= n; ++j )
			if ( b[i] == a[j] )
				d[i][j] = 1 + d[i-1][j-1];
			else
				d[i][j] = max( d[i-1][j], d[i][j-1] );
	}

	fout << d[m][n] << '\n';

	printSol (m, n);
}
