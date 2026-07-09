#include <bits/stdc++.h>

using namespace std;

int t, a, b;

int cmmdc(int a, int b) {
    if (!b)
        return a;
    return cmmdc(b, a % b);
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << cmmdc(a, b) << "\n";
    }
}
