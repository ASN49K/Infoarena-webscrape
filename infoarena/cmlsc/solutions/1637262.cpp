#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

using VI = vector<int>;
using VVI = vector<VI>;

int n, m, lmax;
VI a, b, t;
VVI c;

void Read();

int main()
{
    Read();
    c = VVI(n + 1, VI(n + 1));
    t = VI(n + 1);
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if ( a[i] == b[j] )
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            lmax = max(lmax, c[i][j]);
        }
    for ( int cnt = 0, i = n, j = m; i; )
        if ( a[i] == b[j] )
        {
            t[++cnt] = a[i];
            --i;
            --j;
        }
        else
            if ( c[i][j - 1] > c[i - 1][j] )
                --j;
            else
                --i;
    os << lmax << "\n";
        for ( int i = lmax; i; --i )
            os << t[i] << " ";
    is.close();
    os.close();
    return 0;
}

void Read()
{
    is >> n >> m;
    a = VI(n + 1);
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    b = VI(m + 1);
    for ( int i = 1; i <= m; ++i )
        is >> b[i];
}
