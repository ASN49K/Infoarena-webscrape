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

    int sus = 0;
    for ( int k = 0; k <= c[n][m]; ++k )
        for ( int i = sus; i <= n; ++i )
            for ( int j = 1; j <= m; ++j )
                if ( c[i+1][j+1] == c[i][j] + 1 && c[i][j] == k )
                {
                    os << a[i+1] << ' ';
                    sus = i+1;
                    i += n, j += m;
                }
    os << '\n';
    is.close();
    os.close();
    return 0;
}
