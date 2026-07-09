#include <stdio.h>
#include <string.h>

#define SIZE 100000

static const char *fin = "euclid2.in", *fout = "euclid2.out";
static long long v[SIZE+1];

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

    memset(v, 0x01, sizeof v);

    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);

    scanf("%u", &n);
    while (n--) {
        scanf("%lu %lu", &a, &b);
        printf("%lu\n", cmmdc(a, b));
    }

    return 0;
}

