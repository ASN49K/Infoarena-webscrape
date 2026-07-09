#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int nr, prec, a[1030], b[1030], r[1030], dp[1030][1030];

void rec ( int x, int y );

int main()
{
    int n, m, i, j;

    fin >> n >> m;
    for ( i = 1 ; i <= n ; i++ ) fin >> a[i];
    for ( i = 1 ; i <= m ; i++ ) fin >> b[i];

    for ( i = 1 ; i <= n ; i++ ) if ( a[i] == b[1] ) while ( i <= n ) dp[i][1] = 1, i++;
    for ( i = 1 ; i <= m ; i++ ) if ( a[1] == b[i] ) while ( i <= m ) dp[1][i] = 1, i++;

    for ( i = 2 ; i <= n ; i++ )
        for ( j = 2 ; j <= m ; j++ )
            if ( a[i] == b[j] ) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );

    dp[n+1][m+1] = prec = dp[n][m] + 1;
    rec ( n + 1, m + 1 );

    fout << nr << '\n';
    for ( i = nr ; i >= 1 ; i-- ) fout << r[i] << ' ';

    return 0;
}

void rec ( int x, int y )
{
    int i;

    if ( dp[x][y] == 0 );
    else
    {
        for ( i = x - 1 ; i >= 1 ; i-- )
            if ( a[i] == b[y-1] && dp[i][y-1] == prec - 1 )
            {
                r[++nr] = a[i];
                prec--;
                rec ( i, y - 1 );
                return;
            }

        for ( i = y - 1 ; i >= 1 ; i-- )
            if ( a[x-1] == b[i] && dp[x-1][i] == prec - 1 )
            {
                r[++nr] = b[i];
                prec--;
                rec ( x - 1, i );
                return;
            }

        rec ( x - 1, y - 1 );
    }
}
