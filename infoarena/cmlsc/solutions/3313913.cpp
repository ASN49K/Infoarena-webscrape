#include <bits/stdc++.h>

using namespace std;
int dp[1050][1050];
int v[1030];
int m1[1030];
int afis[1102500];
int main()
{
   ifstream cin("cmlsc.in");
   ofstream cout("cmlsc.out");
   int n,m;
   int k=0;
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
    int a=n,b=m;
    while(a>0 && b>0)
    {
        if(dp[a][b]==dp[a-1][b])
            a--;
        else if(dp[a][b]==dp[a][b-1])
            b--;
        else
        {
            afis[k]=v[a];
            k++;
            a--;
            b--;
        }
    }
    for(int i=k-1;i>=0;i--)
    {
        cout<<afis[i]<<" ";
    }
    return 0;
}
