#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define nmax 1030
int a[nmax],b[nmax];
int dp[nmax][nmax];
int t[nmax];
int main()
{
    int n,m,i,j,p;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    g<<dp[n][m]<<'\n';
    p=dp[n][m];
    i=n;
    j=m;
    while(p)
    {
        if(a[i]==b[j])
        {

            t[p]=a[i];
            p-=1;
            i-=1;
            j-=1;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i-=1;
            else
                j-=1;
        }
    }
    for(i=1;i<=dp[n][m];i++)
        g<<t[i]<<" ";
    return 0;
}
