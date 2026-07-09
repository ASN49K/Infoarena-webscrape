#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[1030], b[1030], dp[1030][1030];

void drum (int x, int y) {
    if (x == 0 || y == 0)
        return;
    if (a[x] == b[y]) {
        drum (x-1, y-1);
        g << a[x] << ' ';
    }
    else {
        if (dp[x-1][y] >= dp[x][y-1])
            drum (x-1, y);
        else drum (x, y-1);
    }
}

int main()
{
    f >> n >> m;
    for (int i=1; i<=n; ++i)
        f >> a[i];
    for (int i=1; i<=m; ++i)
        f >> b[i];

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max (dp[i-1][j], dp[i][j-1]);

    g << dp[n][m] << '\n';
    drum (n, m);
    return 0;
}
