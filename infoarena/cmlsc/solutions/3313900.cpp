#include <bits/stdc++.h>

using namespace std;
int dp[1050][1050];
int v[1030];
int m1[1030];
queue<int>pq;
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
                pq.push(v[i]);
                dp[i][j]++;
            }
        }
    }
    cout<<dp[n][m]<<endl;
    while(!pq.empty())
    {
        cout<<pq.front()<<" ";
        pq.pop();
    }
    return 0;
}
