#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAXNM = 1030;
int n, m, a[MAXNM], b[MAXNM], ml[MAXNM][MAXNM], sol[MAXNM], ns;

int main()
{
    int i, j;

    fin >> n >> m;

    for ( i = 1; i <= n; i++ )
        fin >> a[i];
    for ( i = 1; i <= m; i++ )
        fin >> b[i];

    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
            if ( a[i] == b[j] )
                ml[i][j] = ml[i - 1][j - 1] + 1;
            else
                ml[i][j] = max( ml[i - 1][j], ml[i][j - 1] );

    for ( i = n, j = m; i; )
        if ( a[i] == b[j] )
            sol[++ns] = a[i], i--, j--;
        else
            if ( ml[i - 1][j] < ml[i][j - 1] )
                j--;
            else
                i--;

    fout << ns << '\n';
    for ( i = ns; i >= 1; i-- )
        fout << sol[i] << ' ';
    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}
