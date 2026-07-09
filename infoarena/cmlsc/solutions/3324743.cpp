#include <fstream>

using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int a[1025],b[1025],dp[1025][1025];
void drum(int i,int j,int l)
{
    if (l==0)
        return;
    if (a[i]==b[j])
    {
        drum(i-1,j-1,l-1);
        cout<<a[i]<<" ";
    }
    else
    {
        if (dp[i][j-1]>dp[i-1][j])
        {
            drum(i,j-1,l);
        }
        else
            drum(i-1,j,l);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][m]<<'\n';
    drum(n,m,dp[n][m]);
    return 0;
}
