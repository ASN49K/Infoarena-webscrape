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
    for(int i = n, j = m; i >= 1 && j >= 1;)
    {
        if(A[i] == B[j])
            v.push_back(A[i]), i--, j--;
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
    }
    }
    reverse(v.begin(),v.end());
}

/////////////////////////////////////////////////
int main()
{
    f >> n >> m;
    for(int i=1;i<=n;++i)
        f >> A[i];
    for(int i=1;i<=m;++i)
        f >> B[i];
    solve();
    //g << dp[1][1] << '\n';
    //for(int i=0;i<v.size();++i)
        //g << v[i] << ' ';
}
