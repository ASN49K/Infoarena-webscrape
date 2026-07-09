#include <bits/stdc++.h>
#define pb push_back
using namespace std;
ifstream fin ( "cmlsc.in" );
ofstream fout ( "cmlsc.out" );
int n, m;
int dp[1025][1025];
int a[1025];
int b[1025];
vector<int>sol;
void rec_sol ( int n, int m ) {
    if ( n == 0 || m == 0 )
        return;

    if ( a[n] == b[m] ) {
        sol.pb ( a[n] );
        rec_sol ( n - 1, m - 1 );
    } else {
        if ( dp[n - 1][m] > dp[n][m - 1] )
            rec_sol ( n - 1, m );
        else rec_sol ( n, m - 1 );
    }
}
int main() {
    fin >> n >> m;

    for ( int i = 1; i <= n; i++ )
        fin >> a[i];

    for ( int j = 1; j <= m; j++ )
        fin >> b[j];

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            dp[i][j] = ( a[i] == b[j] ? dp[i - 1][j - 1] + 1 : max ( dp[i - 1][j], dp[i][j - 1] ) );

    fout << dp[n][m] << '\n';
    rec_sol ( n, m );
    reverse ( sol.begin(), sol.end() );

    for ( auto it : sol )
        fout << it << ' ';

    return 0;
}
