#include <fstream>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int m, n, a[1025], d[1025][1025], b[1025], s[1025];
int cnt;

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
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max( d[i-1][j], d[i][j-1] );
    for ( int i = n, j = m; i; )
        if ( a[i] == b[j] )
            s[++cnt] = a[i], i--, j--;
        else
        {
            if( d[i-1][j] < d[i][j-1] )
                j--;
            else
                i--;
        }
    os << cnt << '\n';
    for ( int i = cnt; i > 0; i-- )
        os << s[i] << ' ';
    is.close();
    os.close();
    return 0;
}
