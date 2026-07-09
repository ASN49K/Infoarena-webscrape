#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (a < 0 && b < 0) a = -a, b = -b;
    if (a > b) swap(a, b);
    while (a > 0) {
        int r = b % a;
        b = a;
        a = r;
    }
    return b;
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
