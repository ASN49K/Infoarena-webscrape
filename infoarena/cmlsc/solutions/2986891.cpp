#include <bits/stdc++.h>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int N = 1025;

int n, m, a[N], b[N], dp[N][N];
stack<int> s;

int main()
{
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        f >> a[i];
    for (int i = 1; i <= m; i++)
        f >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    g << dp[n][m] << '\n';
    int i = n, j = m;
    while (dp[i][j]){
        if (dp[i - 1][j] == dp[i][j]) i--;
        else if (dp[i][j - 1] == dp[i][j]) j--;
        else { s.push(a[i]); i--; j--; }
    }
    while (!s.empty()) { g << s.top() << ' '; s.pop(); }
    
    return 0;
}