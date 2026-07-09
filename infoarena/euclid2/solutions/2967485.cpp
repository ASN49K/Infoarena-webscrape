#include <bits/stdc++.h>

#define ll long long

using namespace std;

int tc;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    cin >> tc;
    while (tc--) {
        int x, y;
        cin >> x >> y;
        cout << gcd(x, y) << '\n';
    }
}