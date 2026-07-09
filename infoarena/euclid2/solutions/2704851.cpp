#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t, a, b;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    in >> t;
    
    while (t--) {
        in >> a >> b;
        out << gcd(a, b) << '\n';
    }

    return 0;
}