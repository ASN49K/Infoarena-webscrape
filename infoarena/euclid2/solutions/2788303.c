#include <stdio.h>

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T, a, b;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &a, &b);
        while(b)
            b ^= a ^= b ^= a %= b;
        printf("%d\n", a);
    }
}