#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main() {
	int n, m;
    f >> n >> m;
    int a[n+1], b[m+1], dp[n+1][m+1];
    for( int i = 1; i <= n; ++i )
        f >> a[i];
    for( int i = 1; i <= m; ++i )
        f >> b[i];
    for( int i = 0; i <= n; ++i )
    {
        for( int j = 0; j <= m; ++j )
            dp[i][j] = 0;
    }
    for( int i = 1; i <= n; ++i )
    {
        for( int j = 1; j <= m; ++j )
        {
            if( a[i] == b[j] )
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << "\n";
    int i = n, j = m;
    int v[dp[n][m]+1];
    v[0] = 0;
    while( i >= 1 && j >= 1 )
    {
        if( a[i] == b[j] )
            ++v[0], v[v[0]] = a[i], --i, --j;
        else
        {
            if( dp[i-1][j] > dp[i][j-1] )
                --i;
            else
                --j;
        }
    }
    for( int i = v[0]; i >= 1; --i )
    {
        g << v[ i ] << " ";
    }
    return 0;
}
