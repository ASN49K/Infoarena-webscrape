#include <bits/stdc++.h>

using namespace std;

int main() {
        freopen ("euclid.in", "r", stdin);
        freopen ("euclid.out", "w", stdout);

        int t;
        cin >> t;
        for (int tc = 1; tc <= t; tc++) {
                int a, b;
                cin >> a >> b;
                cout << __gcd(a, b) << "\n";
        }
}
