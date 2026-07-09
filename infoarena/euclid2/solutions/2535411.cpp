#include <bits/stdc++.h>

using namespace std;

int t, a, b;

int gcd(int a, int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << gcd(a, b) << "\n";
    }
}
