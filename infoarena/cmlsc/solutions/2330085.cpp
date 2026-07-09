#include <iostream>
#include <fstream>
#define NMAX 1024

using namespace std;

ifstream fin ( "cmlsc.in" );
ofstream fout ( "cmlsc.out" );

int x[1 + NMAX], y[1 + NMAX];
int dp[1 + NMAX][1 + NMAX];
int n, m;

void afisare ( int i, int j ) {
    if ( dp[i][j] ) {
        if ( x[i] == y[j] )
            afisare ( i - 1, j - 1 ), fout << x[i] << " ";
        else if ( dp[i][j] == dp[i - 1][j] )
            afisare ( i - 1, j );
        else
            afisare ( i, j - 1 );
    }
}

int main() {
    fin >> m >> n;
    for ( int i = 1; i <= m; i++ )
        fin >> x[i];
    for ( int i = 1; i <= n; i++ )
        fin >> y[i];
    for ( int i = 1; i <= m; i++ ) {
        for ( int j = 1; j <= n; j++ ) {
            if ( x[i] == y[j] )
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max ( dp[i - 1][j], dp[i][j - 1] );
        }
    }
    fout << dp[m][n] << '\n';
    afisare ( m, n );
    return 0;
}
