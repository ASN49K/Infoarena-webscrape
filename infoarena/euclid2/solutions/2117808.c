#include <stdio.h>

int cmmdc(int a, int b)
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

    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }

    return 0;
}

