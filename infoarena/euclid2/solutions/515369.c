#include <stdio.h>

int main(void) {

    long a, b, r;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%ld %ld", &a, &b);

    while(b) {

        r = b;
        b = a % b;
        a = r;
    }

    printf("%ld", a == 1 ? 0 : a);

    return 0;
}
