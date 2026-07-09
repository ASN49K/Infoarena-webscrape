#include <iostream>
#include <fstream>
#define LL long long
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short v[1025], w[1025], dp[1025][1025], k[1025];
int n, m;
int main()
{
    f >> n >> m;
    for(int i=1;i<=n;i++)
    f >> v[i];
    for(int i=1;i<=m;i++)
        f >> w[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(v[i]==w[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    int i=n, j=m, nr=0;
    while(dp[i][j]!=0)
    {
        if(dp[i-1][j] == dp[i][j])
            i--;
        else if(dp[i][j-1] == dp[i][j])
                j--;
        else if(dp[i-1][j-1]<dp[i][j])
        {
            k[++nr]=v[i];
            i--;
            j--;
        }
    }
    g << dp[n][m] << '\n';
    for(int i=nr;i>=1;i--)
        g << k[i] <<' ';
    return 0;
}
