#include <fstream>

using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
signed char a[1025],b[1025];
int dp[1025][1025];
void drum (int i,int j,int k)
{
    if (k>0)
    {
        if (a[i]==b[j])
        {
            drum(i-1,j-1,k-1);
            cout<<(int)a[i]<<" ";
        }
        else
        {
            if (dp[i-1][j]>dp[i][j-1])
            {
                drum(i-1,j,k);
            }
            else
            {
                drum(i,j-1,k);
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int x;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]=x;
    }
    for (int i=1;i<=m;i++)
    {
        cin>>x;
        b[i]=x;
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
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<(int)dp[n][m]<<endl;
    drum (n,m,dp[n][m]);
    return 0;
}
