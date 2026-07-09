#include<bits/stdc++.h>
#define ll long long
#define fi first
#define sc second
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, v[1100], t[1100];
vector<int>ans;
int dp[1100][1100];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>v[i];
    for(int i=1; i<=m; i++)
        f>>t[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(v[i]==t[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    int i=n, j=m;
    g<<dp[n][m]<<'\n';
    while(i)
    {
        if(v[i]==t[j])
        {
            ans.push_back(v[i]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]<dp[i][j-1])
                j--;
            else
                i--;
        }
    }
    for(int i=ans.size()-1; i>=0; i--)
        g<<ans[i]<<' ';
    return 0;
}
