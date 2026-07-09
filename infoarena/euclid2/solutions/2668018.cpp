#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int r;
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        cout << a << endl;
    }
}
