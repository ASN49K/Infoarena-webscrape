#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    int a, b, N;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);

        printf("%d\n", gcd(a, b));
    }
}

