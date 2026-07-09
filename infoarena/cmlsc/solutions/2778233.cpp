#include <bits/stdc++.h>
#define NMAX 1025
#define MMAX 1025

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

stack < int > r;
int dp[NMAX][MMAX];

int main()
{
    int n, m, i, j, a[NMAX], b[MMAX];

    fin >> n >> m;
    for ( i = 1 ; i <= n ; i++ ) fin >> a[i];
    for ( i = 1 ; i <= m ; i++ ) fin >> b[i];

    for ( i = 1 ; i <= n ; i++ ) if ( a[i] == b[1] ) while ( i <= n ) dp[i][1] = 1, i++;
    for ( i = 1 ; i <= m ; i++ ) if ( a[1] == b[i] ) while ( i <= m ) dp[1][i] = 1, i++;

    for ( i = 2 ; i <= n ; i++ )
        for ( j = 2 ; j <= m ; j++ )
            if ( a[i] == b[j] ) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );

    fout << dp[n][m] << '\n';
    for ( i = n; i >=1; i-- )
        for ( j = m; j >= 1; j-- )
            if ( a[i] == b[j] ) r.push ( a[i] ), i--, j--;

    while ( r.empty() == 0 ) fout << r.top() << ' ', r.pop();


    return 0;
}
