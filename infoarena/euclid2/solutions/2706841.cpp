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
    freopen("euclid2.in", "r", stdin); \
    freopen("euclid2.out", "w", stdout);
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
    testcase{
        int a, b;
        cin >> a >> b;
        cout << __gcd(a, b) << '\n';
    }
    return 0;
}
