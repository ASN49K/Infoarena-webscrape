#include <bits/stdc++.h>
using namespace std;
int v1[1025],v2[1025],dp[1025][1025],afis[1025];
int main()
{
#ifdef HOME
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif // HOME
#ifndef HOME
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
#endif // HOME
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,i,j,cnt=0;
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>v1[i];
    for(i=1; i<=m; i++)
        cin>>v2[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+(v1[i]==v2[j]));
    cout<<dp[n][m]<<'\n';
    i=n;
    j=m;
    while(i>=1&&j>=1)
    {
        if(dp[i][j]==dp[i-1][j])
            i--;
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else if(dp[i][j]==1+dp[i-1][j-1])
        {
            afis[++cnt]=v1[i];
            i--;
            j--;
        }
    }
    for(i=cnt; i>=1; i--)
        cout<<afis[i]<<" ";
    return 0;
}
