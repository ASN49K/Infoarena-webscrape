#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;

int a[1026],b[1026];
struct {int l,x1,x2;} dp[1026][1026];

signed main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
    int n,m; fin>>n>>m;
    for(int i=1; i<=n; ++i) fin>>a[i];
    for(int i=1; i<=m; ++i) fin>>b[i];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            dp[i][j] = dp[i-1][j];
            if(dp[i][j].l < dp[i][j-1].l)
                dp[i][j] = dp[i][j-1];
            if(a[i] == b[j] && dp[i][j].l < dp[i-1][j-1].l+1)
            {
                dp[i][j].l = dp[i-1][j-1].l + 1;
                dp[i][j].x1 = i;
                dp[i][j].x2 = j;
            }
        }
    fout<<dp[n][m].l<<'\n';
    vector<int> v;
    int x1 = dp[n][m].x1-1, x2 = dp[n][m].x2-1;
    while(x1 > 0 && x2 > 0)
    {
        v.emplace_back(a[x1+1]);
        auto ceva = dp[x1][x2];
        x1 = ceva.x1-1;
        x2 = ceva.x2-1;
    }
    v.emplace_back(a[x1+1]);
    reverse(v.begin(), v.end());
    for(auto &i:v) fout<<i<<' ';
    return 0;
}
