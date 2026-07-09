#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
#define test " test "
#define ll long long
#define pii pair<int, int>
#define FASTIO   \
    cin.tie(0);  \
    cout.tie(0); \
    ios_base::sync_with_stdio(0);
#define FILES                      \
    freopen("cmlsc.in", "r", stdin); \
    freopen("cmlsc.out", "w", stdout);
#define testcase             \
    int T;    \
    cin >> T; \
    while (T--)
#define vec vector<int>
using namespace std;

int dp[1025][1025];

signed main()
{
    FASTIO; FILES;
    int n, m;
    cin >> n >> m;
    vec a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vec b(m + 1);
    for(int i = 1; i <= m; i++)
        cin >> b[i];

    int mx = 0; vec ans;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            mx = max(mx, dp[i][j]);
        }
    for(int i = n, j = m; i;)
        if(a[i] == b[j])
            ans.push_back(a[i]), i--, j--;
        else if (dp[i][j - 1] > dp[i - 1][j])
            j--;
        else
            i--;
    cout << mx << '\n';
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    return 0;
}
