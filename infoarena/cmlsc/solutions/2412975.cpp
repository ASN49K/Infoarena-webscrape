#include <fstream>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int n, m, x, y, k;

int v1[1137], v2[1137], ans[1137];

int dp[1137][1137];

int main()
{
    in>>n>>m;
    for (register int i=1; i<=n; ++i)
        in>>v1[i];
    for (register int j=1; j<=m; ++j)
        in>>v2[j];
    for (register int i=1; i<=n; ++i)
        for (register int j=1; j<=m; ++j)
            if (v1[i]==v2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max (dp[i-1][j], dp[i][j-1]);
    out<<dp[n][m]<<'\n';
    x=n;
    y=m;
    while (x && y)
        if (v1[x]==v2[y])
        {
            ans[++k]=v1[x];
            --x;
            --y;
        }
        else
        {
            if (dp[x][y]==dp[x-1][y])
                --x;
            else
                --y;
        }
    for (register int i=k; i>=1; --i)
        out<<ans[i]<<" ";
    return 0;
}
