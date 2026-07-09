#include <bits/stdc++.h>

using namespace std;
int dp[1025][1025],a[1025],b[1025],ras[1025];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m,lung=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int cn=n,cm=m;
    lung=dp[n][m];
    while(cn>0&&cm>0)
    {
        if(a[cn]==b[cm])
        {
           ras[lung]=a[cn];
           lung--;
            cn--;
            cm--;
        }
        else if(dp[cn][cm-1]>dp[cn-1][cm])
        cm--;
        else
            cn--;

    }
    cout<<dp[n][m]<<'\n';
    for(int i=1;i<=dp[n][m];i++)
        cout<<ras[i]<<" ";
    return 0;
}
