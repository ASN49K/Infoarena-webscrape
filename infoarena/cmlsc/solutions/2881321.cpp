#include <fstream>

using namespace std;
int a[1050],b[1050];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int j=1;j<=m;++j)cin>>b[j];
    int dp[n+1][m+1];
    pair<int,int>du[n+1][m+1];
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(dp[i-1][j]>dp[i][j-1])
            {
                du[i][j]=make_pair(i-1,j);
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                du[i][j]=make_pair(i,j-1);
                dp[i][j]=dp[i][j-1];
            }
            if(a[i]==b[j])
            {
                if(dp[i-1][j-1]+1>dp[i][j])
                {
                    du[i][j]=make_pair(i-1,j-1);
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            }
        }
    }
    cout<<dp[n][m]<<'\n';
    int sol[m+1],l=0;
    while(dp[n][m]>0)
    {
        int pn=du[n][m].first,pm=du[n][m].second;
        if(pn==n-1&&pm==m-1)
        {
            sol[l++]=a[n];
        }
        n=pn;m=pm;
    }
    for(int i=l-1;i>=0;--i)cout<<sol[i]<<' ';
    return 0;
}
