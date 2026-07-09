#include <fstream>
#include <algorithm>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int n, m, a[1026], b[1026];
int d[1026][1026];
int res[1100];
int k = 0;

void Read();
void Dinamica();
void Write();

int main()
{
    Read();
    Dinamica();
    Write();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    for ( int i = 1; i <= m; ++i )
        is >> b[i];
}
void Dinamica()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if ( a[i] == b[j] )
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max(d[i-1][j], d[i][j-1] );
        }
}
void Write()
{
    int i = n, j = m;
    while ( k < d[n][m] )
    {
        if ( a[i] == b[j] )
        {
            res[k++] = a[i];
            i--;
            j--;
        }
        else
        {
            if ( d[i-1][j] < d[i][j-1] )
                j--;
            else
                i--;
        }
    }
    os << d[n][m] << '\n';
    for ( int i = k-1; i >= 0; --i )
        os << res[i] << ' ';
}
