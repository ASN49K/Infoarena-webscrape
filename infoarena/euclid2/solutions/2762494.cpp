#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int t,a,b;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
//    freopen("euclid2.in", "r", stdin);
//    freopen("euclid2.out", "w", stdout);

    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << gcd(a, b);
    }

    return 0;
}
