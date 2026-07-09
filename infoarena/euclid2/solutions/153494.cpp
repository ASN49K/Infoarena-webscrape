#include <cstdio>

#define FOR(i,n) for(int i = 0; i<n; ++i)

int A,B;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int T;
    scanf("%d", &T);

    FOR(tz,T)
    {
        scanf("%d %d", &A, &B);

        printf("%d\n", gcd(A,B));
    }

    return 0;
}
