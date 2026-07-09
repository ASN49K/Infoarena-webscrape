#include <bits/stdc++.h>

using namespace std;

ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );

const int NMAX = 1030;

int N, M;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];

void Read() {
    fin >> N >> M;
    for( int i = 1; i <= N; ++i )
        fin >> a[i];
    for( int i = 1; i <= M; ++i )
        fin >> b[i];
}

void Remake( int n, int m ) {
    if( n == 0 || m == 0 ) return;

    if( a[n] == b[m] ) { Remake( n - 1, m - 1 ); fout << a[n] << ' '; }
    else
      if( dp[n][m - 1] > dp[n - 1][m - 1] ) Remake( n, m - 1 );
      else Remake( n - 1, m );
}

void Do()
{
    for( int i = 1; i <= N; ++i )
        for( int j = 1; j <= M; ++j )
            if( a[i] == b[j] ) dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );

    fout << dp[N][M] << '\n';

    Remake( N, M );

    /*for( int i = 1; i <= N; ++i ) {
        for( int j = 1; j <= M; ++j )
            fout << dp[i][j] << ' ';
        fout << '\n';
    }*/
}

int main()
{
    Read();
    Do();

    return 0;
}
