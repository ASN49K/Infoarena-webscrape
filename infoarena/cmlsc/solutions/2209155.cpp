#include <bits/stdc++.h>
#define lim 1025

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[lim], b[lim], ans[lim];
int dp[lim][lim];
int n, m, k;

void procesare()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if ( a[i] == b[j] )
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
}

void cautare()
{
    int i = n, j = m;
    while ( i )
    {
        if ( dp[i][j] == dp[i-1][j] )
            i--;
        else
        {
            if ( dp[i][j] == dp [i][j-1] )
                j--;
            else
                if ( dp[i][j] == dp[i-1][j-1]+1 )
                {
                    ans[++k] = a[i];
                    j--;
                    i--;
                }
        }
    }
}

int main()
{
    fin>>n>>m;
    for ( int i = 1; i <= n; ++i )
        fin>>a[i];
    for ( int j = 1; j <= m; ++j )
        fin>>b[j];
    procesare();
    cautare();
    fout<<dp[n][m]<<'\n';
    for ( int i = k; i >= 1; --i )
        fout<<ans[i]<<" ";

}
