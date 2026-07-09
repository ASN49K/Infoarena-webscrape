#include <stdio.h>

freopen ("euclid2.in", "r", stdin);
freopen ("euclid2.out", "w", stdout);

int euclid2(int a, int b)
{
    int r = 0;

    while (b > 1)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int n, a, b;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", euclid2(a, b));
    }
    return 0;
}