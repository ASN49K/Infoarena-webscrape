#include <fstream>
#define N 1024

using namespace std;

int a[N+5],b[N+5],dp[N+5][N+5],sol[N+5];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m;
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    g<<dp[n][m]<<"\n";
    int k=0;
    while(n and m)
    {
        if(a[n]==b[m])
        {
            sol[++k]=a[n];
            n--;
            m--;
            continue;
        }
        if(dp[n-1][m]>dp[n][m-1])
            n--;
        else
            m--;
    }
    for(int i=k;i>=1;i--)
        g<<sol[i]<<" ";
    return 0;
}
