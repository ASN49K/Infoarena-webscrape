#include <stdio.h>

static unsigned long cmmdc(unsigned long a, unsigned long b)
{
    if (a % b)
        return cmmdc(b, a % b);
    return b;
}

int main(void)
{
    unsigned n;
    unsigned long a, b;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%u", &n);
    while (n--) {
        scanf("%lu %lu", &a, &b);
        printf("%lu\n", cmmdc(a, b));
    }

    return 0;
}

