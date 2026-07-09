#include <bits/stdc++.h>
#define cin fin
#define cout fout
using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int n,m,i,j,v[1030],v2[1030],dp[1030][1030],ras[1030],cnt;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(j=1;j<=m;j++)
    {
        cin>>v2[j];
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(v[i]==v2[j])
                dp[i][j]=dp[i-1][j-1]+1;
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    cout<<dp[n][m]<<'\n';
    while(n && m)
    {
        if(v[n]==v[m])
        {
            ras[++cnt]=v[n];
            n--;
            m--;
        }
            else
            if(dp[n-1][m]>=dp[n][m-1])
                n--;
            else
                m--;
    }
    for(i=cnt;i>=1;i--)
        cout<<ras[i]<<" ";
    return 0;
}
