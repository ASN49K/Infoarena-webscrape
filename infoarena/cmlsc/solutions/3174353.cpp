#include <iostream>

using namespace std;

int dp[1025][1025];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    cout<<dp[n][m]<<'\n';
    int i=n, j=m;
    int ans[1025], k=0;
    for(int target=dp[n][m]; target>0;)
    {
        if(a[i]==b[j])
        {
            ans[target--]=a[i];
            i--;
            j--;
            k++;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                --i;
            else
                --j;
        }
    }
    for(int it=1; it<=k; it++)
        cout<<ans[it]<<' ';
    return 0;
}
