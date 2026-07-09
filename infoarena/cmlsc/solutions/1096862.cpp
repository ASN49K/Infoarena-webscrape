#include<fstream>
#include<algorithm>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int a[1025], b[1025], c[1025][1025];
int n, m;

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    for ( int j = 1; j <= m; ++j )
        is >> b[j];

    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if ( a[i] == b[j] )
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }

    os << c[n][m] << '\n';

    int k = 0, i = n, j = m;
    int res[1025];
    while ( k != c[n][m] )
    {
        if ( a[i] == b[j] )
        {
            res[k++] = a[i];
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
    }

    for ( i = k - 1; i >= 0; --i )
        os << res[i] << ' ';

    is.close();
    os.close();
    return 0;
}
