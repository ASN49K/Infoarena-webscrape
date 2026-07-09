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

int gcd(int a, int b) {
    int r = a % b;

    while (r) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t = 1;
    cin >> t;

    do {
        solve();
    } while (--t);
}