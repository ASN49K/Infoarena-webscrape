#include <stdio.h>

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

    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &x, &y);
        printf("%lld\n", gcd(x, y));
    }

    return 0;
}