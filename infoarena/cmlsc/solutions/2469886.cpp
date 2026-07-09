#include <bits/stdc++.h>

using namespace std;
int n, m, dp[1025][1025], x[1025], y[1025];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
stack <int> st;

void read()
{
    f >> n >> m;
    for (int i = 1; i <= n; ++i)
        f >> x[i];
    for (int i = 1; i <= m; ++i)
        f >> y[i];
}

void solve()
{
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
        if (x[i] == y[j])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    g << dp[n][m] << "\n";

}

void retrace(int ln, int col)
{
    if (ln == 0 || col == 0)
        return;
    if (dp[ln][col] > max(dp[ln][col - 1], dp[ln - 1][col])) {
        st.push(x[ln]);
        retrace(ln - 1, col - 1);
    }
    else
        if (dp[ln][col - 1] > dp[ln - 1][col])
            retrace(ln, col - 1);
        else
            retrace(ln - 1, col);
}

void show()
{
    while (!st.empty()){
        g << st.top() << " ";
        st.pop();
    }
}

int main()
{
    read();
    solve();
    retrace(n, m);
    show();
    return 0;
}
