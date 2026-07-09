#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1030], b[1030];
int dp[1030][1030];
vector<int> subsir;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << '\n';

    for (int i = n, j = m; i; ) {
        if (a[i] == b[j]) {
            subsir.push_back(a[i]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
            i--;
    }
    reverse(subsir.begin(), subsir.end());
    for (int i = 0; i < subsir.size(); i++)
        cout << subsir[i] << " ";

    return 0;
}
