#include <bits/stdc++.h>

#define int long long

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

signed main() {
    int q; in >> q;
    while(q--) {
        int n; in >> n;
        int s = 0;
        for(int i = 1; i <= n; i++) {
            int x; in >> x;
            s = s ^ x;
        }
        out << (s != 0 ? "DA\n" : "NU\n");
    }
    return 0;
}
