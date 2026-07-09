#include <bits/stdc++.h>

#define int long long

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

signed main() {
    int n;
    in >> n;
    for(int i = 1; i <= n; i++) {
        int a, b; in >> a >> b;
        while(b != 0) {
            int aux = a;
            a = b;
            b = aux % a;
        }
    }
    out << a << '\n';
    return 0;
}
