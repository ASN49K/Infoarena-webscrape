#include <stdio.h>

long t, a, b;

long gcd(long a, long b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &t);

    for (long i=1; i<=t; ++i)
     {
         scanf("%d %d", &a, &b);
         printf("%d\n", gcd(a,b));
     }


return 0;
}
