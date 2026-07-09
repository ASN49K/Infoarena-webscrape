#include <bits/stdc++.h>

std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");

int gcd(int a, int b) {
    if (b == 0)
        return a;
    
    return gcd(b, a % b);
}

void solve() {
    int a, b;
    in >> a >> b;

    out << gcd(a, b) << '\n';
}

int main() {
    int t;

    in >> t;
    while (t--) {
        solve();
    }


    return 0;
}