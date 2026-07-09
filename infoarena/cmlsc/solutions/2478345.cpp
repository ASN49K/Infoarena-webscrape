#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,dp[1030][1030],a[1030],b[1030],ans[1030],k;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++) in>>a[i];
    for(int i=1;i<=m;i++) in>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    out<<dp[n][m]<<'\n';
    int l=n,c=m;
    while(l>0&&c>0)
    {
        if(a[l]==b[c])
        {
            ans[++k]=a[l];
            l--;
            c--;
        }
        else
        {
            if(dp[l-1][c]>dp[l][c-1]) l--;
            else c--;
        }
    }
    for(int i=k;i>0;i--) out<<ans[i]<<" ";
    return 0;
}
