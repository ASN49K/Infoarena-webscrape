#include <fstream>
#include <cstdio>

using namespace std;
#define MAXNM 1024
ifstream cin ( "cmlsc.in" );
ofstream cout ( "cmlsc.out" );
int v[MAXNM], v1[MAXNM], dp[MAXNM][MAXNM], a[MAXNM];
int main()
{
    int n, m, i, j, ans;
    cin >> n >> m;
    for ( i = 1; i <= n; i++ )
      cin >> v[i];
    for ( i = 1; i <= m; i++ )
      cin >> v1[i];
    dp[0][0] = 0;
    for ( i = 1; i <= n; i++ )
      for ( j = 1; j <= m; j++ )
         if ( v[i] == v1[j] )
            dp[i][j] = dp[i - 1][j - 1] + 1;
          else
            dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );
    cout << dp[n][m] << "\n";
    ans = dp[n][m];
    i = n;
    j = m;
    while ( ans ) {
        if ( dp[i - 1][j] == ans )
          i--;
        else if ( dp[i][j - 1] == ans )
          j--;
        else {
          a[ans] = v[i];
          i--;
          j--;
          ans--;
        }
    }
    for ( i = 1; i <= dp[n][m]; i++ )
      cout << a[i] << " ";
    return 0;
}
