#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
// #define f cin
// #define g cout
int n, m, v[1030], a[1030], dp[1030][1030];
vector<int> rez;
int main()
{
    ios_base::sync_with_stdio(false);
    f.tie(nullptr);
    g.tie(nullptr);
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        f >> v[i];
    for (int i = 1; i <= m; i++)
        f >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (v[i] == a[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    while (n && m)
        if (v[n] == a[m])
            rez.push_back(v[n]), n--, m--;
        else if (dp[n - 1][m] > dp[n][m - 1])
            n--;
        else
            m--;
    g << rez.size() << '\n';
    for (auto it = rez.rbegin(); it != rez.rend(); it++)
        g << *it << " ";
    return 0;
}
