#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1025;
int a[NMAX], b[NMAX], dp[NMAX][NMAX], sir[NMAX];
int main()
{
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
        cin >> a[i];
    for( int i = 1; i <= m; i++ )
        cin >> b[i];
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ ){
            if( a[i] == b[j] )
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    cout << dp[n][m] << "\n";
    int i = n;
    int j = m;
    int k = 0;
    while( i ){
        if( a[i] == b[j] ){
            sir[++k] = a[i];
            i--;
            j--;
        }
        else{
            if( dp[i-1][j] < dp[i][j-1] )
                j--;
            else
                i--;
        }
    }
    while(k)
        cout << sir[k--] << " ";
    return 0;
}
