#include <stdio.h>

static const char *fin = "euclid2.in", *fout = "euclid2.out";

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

    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);

    scanf("%u", &n);
    while (n--) {
        scanf("%lu %lu", &a, &b);
        printf("%lu\n", cmmdc(a, b));
    }

    return 1;
}

