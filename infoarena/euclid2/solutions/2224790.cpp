#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        cout << __gcd(x, y) << '\n';
    }
    return 0;
}

