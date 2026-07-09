#include <fstream>
#include <algorithm>
using namespace std;

int a[1000], b[1000];
int c[1000][1000];

void Afis( int i, int j );

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
	int n, m;
	fin >> m >> n;
	int i, j;
	for ( i = 1; i <= m; i++)
		fin >> a[i];
	for ( i = 1; i <= n; i++)
		fin >> b[i];
	for ( i = 1; i <= m; i++)
		for ( j = 1; j <= n; j++)
			if ( a[i] == b[j] )
				c[i][j] = 1 + c[i-1][j-1];
			else
				c[i][j] = max ( c[i-1][j], c[i][j-1] );
	fout << c[m][n] << '\n';
	Afis(m , n);
	fin.close();
	fout.close();
	return 0;
}

void Afis ( int i, int j )
{
	  if ( i == 0 || j == 0 )
        return;
    if ( a[i] == b[j] )
    {
        Afis ( i-1, j-1 );
        fout << a[i] << ' ';
    }    
    else
        if ( c[i-1][j] > c[i][j-1] )
                Afis ( i-1, j );
        else
                Afis ( i, j-1 );
}