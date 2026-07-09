#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025], b[1025], m, n;
int dp[1025][1025];
int best[1025], len;

int main(void)
{
    f>>m>>n;
    for(int i=1; i<=m; ++i)f>>a[i];
    for(int j=1; j<=n; ++j)f>>b[j];
    //construin tabelul
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //refacem traseul
    for(int i=m, j=n; i>0&&j>0; )
        if(dp[i][j]!=max(dp[i-1][j],dp[i][j-1]))
        {
            best[++len]=a[i];
            --i;
            --j;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            --i;
        else
            --j;
    g<<len<<'\n';
    for(int i=len; i>=1; --i)
        g<<best[i]<<' ';
    g<<'\n';
    f.close();
    g.close();
    return 0;
}
