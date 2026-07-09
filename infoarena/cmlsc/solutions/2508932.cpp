#include <iostream>
#include <fstream>

using namespace std;

const int NMAX = ( 1 << 10 );

int dp[NMAX + 1][NMAX + 1];
int s1[NMAX + 1];
int s2[NMAX + 1];
int rez[NMAX + 1];

int main() {
    ifstream fin( "cmlsc.in" );
    ofstream fout( "cmlsc.out" );
    int n, m, l, c, i;
    fin >> n >> m;
    for ( i = 1; i <= n; i ++ ) {
        fin >> s1[i];
    }
    for ( i = 1; i <= m; i ++ ) {
        fin >> s2[i];
    }
    for ( l = 1; l <= n; l ++ ) {
        for ( c = 1; c <= m; c ++ ) {
            if ( s1[l] == s2[c] ) {
                dp[l][c] = dp[l - 1][c - 1] + 1;
            } else {
                dp[l][c] = max( dp[l - 1][c], dp[l][c - 1] );
            }
        }
    }
    i = dp[n][m];
    fout << i << '\n';
    l = n;
    c = m;
    while ( l > 0 && c > 0 ) {
        if ( s1[l] == s2[c] ) {
            rez[i] = s1[l];
            l --;
            c --;
            i --;
        } else {
            if ( dp[l - 1][c] > dp[l][c - 1] ) {
                l --;
            } else
                c --;
        }
    }
    for ( i = 1; i <= dp[n][m]; i ++ )
        fout << rez[i] << ' ';
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}
