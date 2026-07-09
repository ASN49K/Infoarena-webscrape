#include <bits/stdc++.h>
#define FOR(n) for(int i=1;i<=n;++i)
using namespace std;

/////////////////////////////////////////////////
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

/////////////////////////////////////////////////
const int NMAX = 1500;
int n, m, A[NMAX], B[NMAX], dp[NMAX][NMAX], ans;
vector<int>v;

/////////////////////////////////////////////////
inline void solve()
{
    for(int i=n;i>=1;--i)
    {
        for(int j=m;j>=1;--j)
        {
            if(A[i] == B[j])
                dp[i][j] = dp[i+1][j+1]+1;
            else
                dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            ans = max(ans,dp[i][j]);
    int cnt = 1;
    for(int i=n;i>=1;--i)
    {
        for(int j=m;j>=1;--j)
        {
            if(dp[i][j] == cnt)
            {
                v.push_back(A[i]);
                cnt++;
            }
        }
    }
    reverse(v.begin(),v.end());
}

/////////////////////////////////////////////////
int main()
{
    f >> n >> m;
    FOR(n)
        f >> A[i];
    FOR(m)
        f >> B[i];
    solve();
    g << ans << '\n';
    for(auto x : v)
        g << x << ' ';
}
