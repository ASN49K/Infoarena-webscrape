#include <fstream>
using namespace std;

int a[100][100];
int x[100], y[100], i, j, m, n;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

void Citeste();
void Search();
void Write(int i, int j);


int main()
{
	Citeste();
	Search();
	os << a[m][n] << '\n';
	Write(m, n);
    os.close();

	return 0;
}


void Citeste()
{
	is >> m >> n;
	for (  i = 1; i <= m; i++ ) is >> x[i];
	for (  i = 1; i <= n; i++ ) is >> y[i];

}


void Write(int i, int j)
{
	if ( i == 0  ||  j == 0 ) return;
	if ( x[i] == y[j] )
	{
		Write( i - 1, j - 1 );
		os << x[i] << " ";
	}
	else
		if ( a[i-1][j] >= a[i][j-1] )
            Write( i - 1, j );
		else
            Write( i, j - 1 );
}

int Max(int a, int b )
{
	return (a > b) ? a : b;
}

void Search()
{
	for (i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= n; j++ )
			if ( x[i] == y[j] )
                a[i][j] = a[i-1][j-1] + 1;
			else
                a[i][j] = Max(a[i-1][j], a[i][j-1] );

    }
}


