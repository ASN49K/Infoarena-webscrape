#include <stdio.h>

int x, y;

void euclid_cmmdc()
{
    while ((x != 0)&&(y != 0))
    {
        if (x > y)
            x = x % y;
        else
            y = y % x;
    }

    printf("%d\n", x+y);
}

int main()
{
    int n;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d %d", &x, &y);
        euclid_cmmdc();
    }

    return 0;
}
