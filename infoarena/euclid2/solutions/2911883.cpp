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
    #ifndef ONLINE_JUDGE2
        (void)!freopen((Name + ".in").c_str(), "r", stdin);
        (void)!freopen((Name + ".out").c_str(), "w", stdout);
    #endif
}

void solve() {
    int a, b; re(a, b);
    while(b) {
        a %= b;
        swap(a, b);
    }
    wr(a, '\n');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Open("euclid2");

    int t; re(t);
    for(;t;t--) {
        solve();
    }

    return 0;
}