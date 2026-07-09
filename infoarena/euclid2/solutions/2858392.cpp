#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    cout << __gcd(x, y) << '\n';
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
}
