#include <iostream>
#include <fstream>

using namespace std;

ifstream f("clmsc.in");
ofstream g("clmsc.out");

const int N=1025;

int m,n,dp[N][N], a[N], b[N];

void sirul(int l, int c)
{
    if (l==0 || c==0)
        return ;
    if (a[l]==b[c])
    {
        sirul (l-1, c-1);
        g<<a[l]<<" ";
    }
    else
    {
        if (dp[l-1][c]>dp[l][c-1])
            sirul(l-1,c);
        else
            sirul(l,c-1);
    }
}

int main()
{
    f>>n>>m;
    for (int i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for (int i=1;i<=m;i++)
    {
        f>>b[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    g<<dp[n][m]<<"\n";
    sirul(n,m);
    return 0;
}
