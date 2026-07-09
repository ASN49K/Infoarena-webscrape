#include <bits/stdc++.h>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int v1[1025], v2[1025];
int dp[1025][1025];
void solve()
{
    int n, m;
    in >> n >> m;
    for (int i = 1;i<=n;++i)
        in >> v1[i];
    for (int i = 1;i<=m;++i)
        in >> v2[i];
    for (int i = 1;i<=n;++i)
        for (int j = 1;j<=m;++j)
            if (v1[i] == v2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    out << dp[n][m] << '\n';
    vector <int> sol;
    int x = n, y = m;
    while (x >= 1 && y >= 1)
        if (v1[x] == v2[y])
        {
            sol.push_back(v1[x]);
            x--;
            y--;
        }
        else if (dp[x-1][y] > dp[x][y-1])
            x--;
        else
            y--;
    for (int i = sol.size() - 1;i>=0;--i)
        out << sol[i] << ' ';
}
main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
