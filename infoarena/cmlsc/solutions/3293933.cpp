#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[1055],b[1055];
int rez[1055],dp[1055][1055];

int main()
{
    f >> n >> m;

    for (int i=1; i<=n; i++ )
        f >> a[i];
    for (int i=1; i<=m; i++ )
        f >> b[i];

    // dp[i][j] - cel mai lung subsir comun pana la al i lea nr din a si al j lea nr din b

    for (int i=1; i<=n; i++ )
        for (int j=1; j<=m; j++ ) {
            if ( b[j]==a[i] )
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }

    g << dp[n][m] << '\n';

    int i=n,j=m;
    while ( i>=1 && j>=1 && dp[i][j]>0 )
    {
        if ( a[i]==b[j] )
        {
            rez[dp[i][j]]=a[i];
            i--;
            j--;
        }
        else if ( dp[i-1][j]>dp[i][j-1] )
            i--;
        else j--;
    }

    for (int i=1; i<=dp[n][m]; i++ )
        g << rez[i] << " ";
    return 0;
}
