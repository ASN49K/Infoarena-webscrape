#include <bits/stdc++.h>

using namespace std;

const int nmax=1030;

int dp[nmax][nmax];
int a[nmax],b[nmax];

void afisare(int n,int m)
{
    if(dp[n][m])
    {
        if(a[n]==b[m]) afisare(n-1,m-1); else
        if(dp[n][m]==dp[n-1][m]) afisare(n-1,m); else afisare(n,m-1);
        if(a[n]==b[m]) cout<<a[n]<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1; else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    cout<<dp[n][m]<<"\n";
    afisare(n,m);
}
