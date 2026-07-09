#include <fstream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1001],b[1001];
int dp[1001][1001];
int ans[1001];
int main()
{
    int n,m,i,j;
    in>>n>>m;
    for(i=1; i<=n; i++)
    {
        in>>a[i];
    }
    for(i=1; i<=m; i++)
    {
        in>>b[i];
    }
    for(i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cnt=0;
    for(i=n, j=m; i>=1 && j>=1; i,j)
    {
        if(a[i]==b[j])
        {
            ans[++cnt]=a[i];
            j--;
            i--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    for (i=cnt; i>=1; i--)
    {
        out<<ans[i]<<" ";
    }
    return 0;
}
