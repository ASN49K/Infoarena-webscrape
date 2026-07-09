#include <bits/stdc++.h>
#define DimMax 1024

using namespace std;

ifstream fin ( "cmlsc.in" );
ofstream fout ( "cmlsc.out" );

int n, m;
int a[DimMax + 1], b[DimMax + 1];
int dp[DimMax + 1][DimMax + 1];
int sir[DimMax + 1];

int main()
{
    fin >> n >> m;
    for ( int i = 1; i <= n; i++ ) fin >> a[i];
    for ( int j = 1; j <= m; j++ ) fin >> b[j];

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            if ( a[i] == b[j] ) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    fout << dp[n][m] << '\n';
    for ( int i = n, j = m; i > 0 && j > 0; )
    {
        if ( a[i] == b[j] )
        {
            sir[++sir[0]] = a[i];
            i--; j--;
        }
        else if ( dp[i - 1][j] > dp[i][j - 1] ) i--;
        else j--;
    }
    for ( int i = sir[0]; i > 0; i-- )
        fout << sir[i] << " ";
    return 0;
}
