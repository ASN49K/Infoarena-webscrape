#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int NMAX = 1025;
int a[NMAX], b[NMAX], dp[NMAX][NMAX], sir[NMAX];
int main()
{
    int n, m;
    in >> n >> m;
    for( int i = 1; i <= n; i++ )
        in >> a[i];
    for( int i = 1; i <= m; i++ )
        in >> b[i];
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ ){
            if( a[i] == b[j] )
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    int i = n;
    int j = m;
    int k = 0;
    while( i && j ){
        if( a[i] == b[j] ){
            sir[k++] = a[i];
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
    out << k << "\n";
    k--;
    while( k >= 0 )
        out << sir[k--] << " ";
    return 0;
}
