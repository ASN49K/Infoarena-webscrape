#include <fstream>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int m, n;
int a[1025], b[1025];
int c[1025][1025];
int t[1025];
int maxim;

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    for ( int i = 1; i <= m; ++i )
        is >> b[i];
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if ( a[i] == b[j] )
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
            if ( c[i][j] > maxim )
                maxim = c[i][j];
    }
    int cnt = 0;
    for ( int i = n, j = m; i; )
    {
        if ( a[i] == b[j] )
            t[++cnt] = a[i], --i, --j;
        else
            if ( c[i][j - 1] > c[i - 1][j] )
                --j;
            else
                --i;
    }
    os << maxim << "\n";
    for ( int i = maxim; i; --i )
        os << t[i] << " ";
    is.close();
    os.close();
    return 0;
}
