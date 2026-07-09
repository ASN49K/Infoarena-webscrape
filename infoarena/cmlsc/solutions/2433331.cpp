#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,v[2000],h[2000];
int dp[2000][2000];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>v[i];
    for(int i=1; i<=m; i++)
        f>>h[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(v[i]==h[j])
                dp[i][j]=dp[i-1][j-1]+1;
        }
    g<<dp[n][m]<<endl;
    int p=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(dp[i][j]>p)
            {
                g<<v[i]<<" ";
                p=dp[i][j];
            }
    return 0;
}
