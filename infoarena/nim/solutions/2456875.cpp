#include <bits/stdc++.h>

using namespace std;

int n, t;

int main() {
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    cin >> t;
    while (t --) {
        cin >> n;
        int xorSum = 0;
        for (int i = 1; i <= n; ++i) {
            int value;
            cin >> value;
            xorSum ^= value;
        }
        if (xorSum > 0) {
            cout << "DA\n";
        } else {
            cout << "NU\n";
        }
    }
    return 0;
}
