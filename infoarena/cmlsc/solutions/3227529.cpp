#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int dp[1025][1025];
int main()
{
    int m, n, a[1025], b[1025];
    f >> m >> n;
    for(int i = 1; i <= m; i++)
        f >> a[i];
    for(int i = 1; i <= n; i++)
        f >> b[i];
    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--)
            if(a[j] == b[i])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
    g << dp[1][1];
    return 0;
}
