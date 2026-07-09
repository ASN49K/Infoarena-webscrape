#include <stdio.h>
#include <stdlib.h>

int t, x, y;

int cmmdc(int a, int b)
{
    if (!b) return a;
    return cmmdc(b, a % b);
}

int main(void)
{
    int i;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    for (i=1;i<=t;i++)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", cmmdc(x, y));
    }

    return 0;
}
