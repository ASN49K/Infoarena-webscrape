#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1024;

int dp[NMAX + 1][NMAX + 1];

int a[NMAX + 1];
int b[NMAX + 1];

int main() {
    ifstream fin( "cmlsc.in" );
    ofstream fout( "cmlsc.out" );
    int n, m;

    fin >> n >> m;

    for ( int i = 1; i <= n; i ++ ) {
        fin >> a[i];
    }
    for ( int i = 1; i <= m; i ++ ) {
        fin >> b[i];
    }
    for ( int i = 1; i <= n; i ++ ) {
        for ( int j = 1; j <= m; j ++ ) {
            dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );
            if ( a[i] == b[j] ) {
                dp[i][j] = max( dp[i][j], dp[i - 1][j - 1] + 1 );
            }
        }
    }
    fout << dp[n][m] << '\n';

    vector <int> ans;
    while ( n > 0 && m > 0 ) {
        if ( dp[n][m] == dp[n - 1][m - 1] + 1 ) {
            ans.push_back( a[n] );
            n --;
            m --;
        } else if ( dp[n - 1][m] > dp[n][m - 1] ) {
            n --;
        } else {
            m --;
        }
    }
    reverse( ans.begin(), ans.end() );
    for ( auto x : ans ) {
        fout << x << ' ';
    }
    fout << '\n';
    return 0;
}