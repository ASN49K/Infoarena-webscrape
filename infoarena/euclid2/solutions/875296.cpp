#include <cstdio>

unsigned gcd(unsigned x, unsigned y)
{
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
    {
        unsigned x, y;
        scanf("%u %u", &x, &y);
        printf("%u\n", gcd(x, y));
    }

    return 0;
}
