//#DEFINE DEBUG_MODE

#include <cstdio>
#include <cstdlib>

typedef long long int LL;

LL gcd(LL a, LL b) {
    while(b) {
        LL aux = a;
        a = b;
        b = aux%a;
    }
    return a;
}

int main() {
#ifdef DEBUG_MODE
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        LL a, b;
        scanf("%lld%lld", &a, &b);
        printf("%lld\n", gcd(a, b));

    }
}
