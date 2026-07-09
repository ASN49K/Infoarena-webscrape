#include <fstream>
#include <iomanip>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int a[1025], b[1025], d[2050], c[1025][1025];
int m, n, k;

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; i++ )
        is >> a[i];
    for ( int i = 1; i <= m; i++ )
        is >> b[i];
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            if ( a[i] == b[j] )
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max( c[i-1][j], c[i][j-1] );
    os << c[n][m] << '\n';
    for ( int i = n, j = m; i; )
        if ( a[i] == b[j] )
        {
            d[++k] = a[i];
            i--;
            j--;
        }
        else
        {
            if ( c[i][j-1] > c[i-1][j] )
                j--;
            else
                i--;
        }
    for ( int i = k; i > 0; i-- )
        os << d[i] << ' ';
    is.close();
    os.close();
    return 0;
}
