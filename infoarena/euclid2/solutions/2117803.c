#include <stdio.h>

static int cmmdc(int a, int b)
{
    if (a % b != 0)
        return cmmdc(b, a % b);
    return b;
}

int main(void)
{
    int n, a, b;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%u", &n);
    while (n--) {
        scanf("%u %u", &a, &b);
        printf("%u\n", cmmdc(a, b));
    }

    return 0;
}

