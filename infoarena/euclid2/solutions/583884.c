/**
 * user: caen1
 * file: infoarena/euclid2.c
 * date: 23 apr 2011
**/
#include <stdio.h>

#define IN "euclid2.in"
#define OUT "euclid2.out"

int main(void) {

    long a, b, r, t;

    (void) freopen(IN, "r", stdin);
    (void) freopen(OUT, "w", stdout);

    (void) scanf("%ld", &t);

    while(t > 0) {

        (void) scanf("%ld %ld", &a, &b);

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
