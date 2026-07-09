#include <stdio.h>

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

FILE *f, *g;

long n;

long cmmdc(long x, long y) {
        long r = 1;

        for (; r != 0; ) {
            r = MAX(x, y) % MIN(x, y);
            x = MIN(x, y); y = r;
        }
        return x;
}

int main() {
        long a, b;

        f = freopen(FIN, "r", stdin);
        g = freopen(FOUT, "w", stdout);

        scanf("%ld", &n);

        for (int i = 0; i < n; i++) {
                scanf("%ld%ld", &a, &b);
                printf("%ld\n", cmmdc(a, b));
        }

        fclose(f);
        fclose(g);
}
