#include <bits/stdc++.h>
#define NM (1<<11)
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,v[NM];
int m,t[NM];
int dp[NM][NM];
vector <int> road;
int main()
{   f>>n>>m;
    for(int i=1; i<=n; i++) f>>v[i];
    for(int i=1; i<=m; i++) f>>t[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {   if(v[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    g<<dp[n][m]<<'\n';
    while(n && m)
    {   if(v[n]==t[m])
        {   road.push_back(v[n]);
            n--;
            m--;
        }
        else
            if(dp[n-1][m]<dp[n][m-1]) m--;
                else n--;
    }
    int lg=road.size();
    for(int i=lg-1; i>=0; i--) g<<road[i]<<' ';
}
