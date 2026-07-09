#include <fstream>
#include <iomanip>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int n, m, a[1025], b[1025], c[1025][1025];
int k, s[1025];

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; i++ )
        is >> a[i];
    for ( int j = 1; j <= m; j++ )
        is >> b[j];
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            if ( a[i] == b[j] )
                c[i][j] = 1 + c[i-1][j-1];
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
    os << c[n][m] << '\n';
    for ( int i = n, j = m; i; )
        if ( a[i] == b[j] )
            s[++k] = a[i], i--, j--;
        else
        {
            if ( c[i-1][j] < c[i][j-1] )
                j--;
            else
                i--;
        }
    for ( int i = k; i > 0; i-- )
        os << s[i] << ' ';
    is.close();
    os.close();
    return 0;
}
