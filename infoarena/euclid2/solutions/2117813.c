#include <stdio.h>

int main(void)
{
    int n, a, b, r;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);

        while (b) {
            r = a % b;
            a = b;
            b = r;
        }

        printf("%d\n", a);
    }

    return 0;
}

