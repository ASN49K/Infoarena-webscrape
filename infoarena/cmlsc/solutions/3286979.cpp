#include <bits/stdc++.h>
using namespace std;

const int MAX = 1024;
int a[MAX], b[MAX], ans[MAX], dp[MAX][MAX], k;

int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            ans[++k] = a[i];
            --i, --j;
        }
        else
        {
            if (dp[i-1][j] >= dp[i][j-1])
                --i;
            else
                --j;
        }
    }

    cout << dp[n][m] << "\n";
    for (int i = k; i >= 1; --i)
        cout << ans[i] << " ";

    return 0;
}
