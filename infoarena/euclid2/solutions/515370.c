#include <stdio.h>

int main(void) {

    long a, b, r, t;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%ld", &t);

    while(t > 0) {

        scanf("%ld %ld", &a, &b);

        while(b) {

            r = b;
            b = a % b;
            a = r;
        }

        printf("%ld\n", a);

        --t;
    }

    return 0;
}
