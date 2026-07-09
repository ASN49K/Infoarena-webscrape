#include <bits/stdc++.h>

using namespace std;
int dp[1050][1050];
int v[1030];
int m1[1030];

int main()
{
   ifstream cin("cmlsc.in");
   ofstream cout("cmlsc.out");
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
    cin>>v[i];
    for(int i=1;i<=m;i++)
    cin>>m1[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(v[i]==m1[j])
            {

                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    for(int i=1;i<=n;i++)
    {

    }
    int a=1,b=1;
    for(int i=1;i<=n;i++)
    {
        if(dp[i][m]!=dp[i-1][m])
            cout<<v[i]<<" ";
    }
    return 0;
}
