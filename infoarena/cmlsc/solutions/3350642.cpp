#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(v) begin(v), end(v)
#define al(v, l, r) begin(v) + l, begin(v) + r + 1
#define sz(v) (int)v.size()
#define pb push_back
#define pob pop_back
#define fs first
#define sd second

constexpr int inf = 2e9;
constexpr ll infll = 4e18;
constexpr int N = 1025;

int n, m, a[N], b[N], dp[N][N];
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << "\n";
    int i = n, j = m;
    vector<int> ans;

    while (i && j)  {
        if (a[i] == b[j]) {
            ans.pb(a[i]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(all(ans));
    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";
}