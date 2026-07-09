#include<fstream>
#include<algorithm>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int a[1024], b[1024], c[1024][1024];

int main()
{
    int n, m;
    is >> n >> m;
    for ( int i = 1; i <= n; i++ )
        is >> a[i];
    for ( int j = 1; j <= m; j++ )
        is >> b[j];

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            if ( a[i] == b[j] )
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }

    os << c[n][m];

    is.close();
    os.close();
    return 0;

}
