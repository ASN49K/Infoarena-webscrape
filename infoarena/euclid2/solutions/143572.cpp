#include <stdio.h>

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int a, b, c;

    scanf("%d %d", &a, &b);

    c = gcd(a, b);

    printf("%d\n", c);

    return 0;
}