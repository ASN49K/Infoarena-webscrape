#include <stdio.h>

static unsigned cmmdc(unsigned a, unsigned b)
{
    if (a % b)
        return cmmdc(b, a % b);
    return b;
}

int main(void)
{
    unsigned n, a, b;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%u", &n);
    while (n--) {
        scanf("%u %u", &a, &b);
        printf("%u\n", cmmdc(a, b));
    }

    return 0;
}

