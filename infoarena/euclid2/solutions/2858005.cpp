#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include "bits/stdc++.h"

using namespace std;

using ld = long double;
using ll = long long;
using ull = unsigned long long;

#if defined(ONPC)
#include "bits/debug.h"
#endif

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void solve() {
    int a, b;
    fin >> a >> b;
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    fout << a << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    fin >> tt;
    while(tt--) {
        solve();
    }
}
