#include <fstream>

#define N 1030

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int n, a[N], m, b[N], dp[N][N], ans[N], sz=0;
int main()
{
    in>>n>>m;
    for (register int i=1; i<=n; i++)
        in>>a[i];
    for (register int i=1; i<=m; i++)
        in>>b[i];
    for (register int i=1; i<=n; i++)
        for (register int j=1; j<=m; j++)
            if (a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    out<<dp[n][m]<<"\n";
    int x=n;
    int y=m;
    while(x && y)
        if(a[x]==b[y])
        {
            ans[++sz]=a[x];
            x--;
            y--;
        }
        else
        {
            if(dp[x][y]==dp[x-1][y])
                x--;
            else
                y--;
        }
    for(register int i=sz; i>=1; i--)
        out<<ans[i]<<" ";
    return 0;
}
