#include <stdio.h>

int T, A, B;

int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        if (a == 0) {
            return b;
        }
        b %= a;
    }
    return a;
}

int main(void) {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (; T; --T) {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }

    return 0;
}