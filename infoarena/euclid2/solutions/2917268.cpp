#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t, a, b, d;
    f >> t;
    for (int i = 0 ; i < t ; i++) {
        f >> a >> b;
        if (a > b)
            d = gcd(a, b);
        else 
            d = gcd(b, a);
        g << d << "\n";
    }
    return 0;
}