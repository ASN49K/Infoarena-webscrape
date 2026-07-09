#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");

    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        cout << a << endl;
    }

    return 0;
}
