#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (a < 0 && b < 0) a = -a, b = -b;
    if (a > b) swap(a, b);
    while (a > 0) {
        int r = b % a;
        b = a;
        a = r;
    }
    return b;
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << "\n";
    }
    return 0;
}
