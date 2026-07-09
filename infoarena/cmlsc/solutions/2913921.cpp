#include <bits/stdc++.h>

#define vt vector
#define pb push_back
#define em emplace
#define emb emplace_back

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

void re() {
}

void wr() {
}

template <typename fir, typename ...sec> void re(fir &x, sec&... y) {
    cin >> x;
    re(y...);
}

template <typename fir, typename ...sec> void wr(fir x, sec... y) {
    cout << x;
    wr(y...);
}

inline void Open(const string Name) {
    #ifndef ONLINE_JUDGE
        (void)!freopen((Name + ".in").c_str(), "r", stdin);
        (void)!freopen((Name + ".out").c_str(), "w", stdout);
    #endif
}

void solve() {
    int n, m; re(n, m);
    vt <int> a(n + 1), b(m + 1);
    for(int i = 1;i <= n;i++)
        re(a[i]);
    for(int i = 1;i <= m;i++)
        re(b[i]);

    vt <vt <int>> dp(n + 1, vt <int>(m + 1));
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            dp[i][j] = (a[i] == b[j]? dp[i - 1][j - 1] + 1 :
                max(dp[i - 1][j], dp[i][j - 1]));
        }

    wr(dp[n][m], '\n');

    auto f = [&](auto&& f, int i, int j) {
        if(!i || !j) {
            return;
        }

        if(a[i] == b[j]) {
            f(f, i - 1, j - 1);
            wr(a[i], ' ');
        } else if(dp[i - 1][j] == dp[i][j]) {
           f(f, i - 1, j); 
        } else {
            f(f, i, j - 1);
        }
    };

    f(f, n, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Open("cmlsc");

    int t = 1;
    for(;t;t--) {
        solve();
    }

    return 0;
}