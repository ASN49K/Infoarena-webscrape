#include <bits/stdc++.h>

long long cmmdc(long long a, long long b)
{
    if (b == 0)
        return a;
    else return cmmdc(b, a % b);
}

int main()
{
    std :: freopen("prim.in", "r", stdin);
    std :: freopen("prim.out", "w", stdout);

    int n; scanf("%d", &n);
    while (n --)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", cmmdc(a, b));
    }

    return 0;
}
