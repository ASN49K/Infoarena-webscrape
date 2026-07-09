#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int dim = (1 << 10) + 1;
const int debug = 0;

int n, m;
int a[dim], b[dim], best[dim], ind;
int d[dim][dim];

void write()
{
    if( !debug )
        return;
    for( int i = 1; i <= n; ++i )
    {
        for( int j = 1; j <= m; ++j )
            fout << d[i][j] << ' ';
        fout << '\n';
    }
}

int main()
{
    fin >> n >> m;
    for( int i = 1; i <= n; ++i )
        fin >> a[i];
    for( int i = 1; i <= m; ++i )
        fin >> b[i];
    for( int i = 1; i <= n; ++i )
        for( int j = 1; j <= m; ++j )
            if( a[i] == b[j] )
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    write();
    for( int i = n, j = m; i; )
    {
        if( a[i] == b[j] )
            best[++ind] = a[i--], j--;
        else
            if( d[i - 1][j] < d[i][j - 1] )
                --j;
            else
                --i;
    }
    fout << ind << '\n';
    for( int i = ind; i; --i )
        fout << best[i] << ' ';
    return 0;
}
