#include <stdio.h>
#include <iostream>

using namespace std;

int T;
long long x, y;

long long gcd(long long a, long long b) {
    long long r = a % b;
    while (true) {
        a = b;
        b = r;
        if (0 == b) {
            return a;
        }
        r = a % b;
    }

    return a;
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> x >> y;
        cout << (x < y ? gcd(x, y) : gcd(y, x)) << endl;
    }

    return 0;
}