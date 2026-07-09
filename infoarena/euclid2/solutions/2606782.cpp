#include <cstdio>

int gcd(int a, int b) {
    if(!b)
        return a;
    return gcd(b, a % b);
}

int main() {
    int t, T, a, b;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &T);
    for(t = 1; t <= T; ++t) {
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
}
