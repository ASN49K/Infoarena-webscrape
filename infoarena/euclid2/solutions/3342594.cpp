#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        cout << __gcd(a, b) << '\n';
    }
    
    return 0;
}