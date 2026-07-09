#include <stdio.h>
#define M 1999999973

long long fast_exp(long long n, long long p, long long m)
{
    if (p == 0)
    {
        return 1;
    }

    long long result = n;
    
    long long i;
    for (i = 1; i < p; ++i)   
    {
        result = (result * n) % m;
    }
    
    return result % m;
}

int main()
{
    long long N, P;
    freopen("lgput.in", "r", stdin);
    freopen("lgput.out", "w", stdout);

    scanf("%lld %lld", &N, &P);
    printf("%lld", fast_exp(N, P, M));
    
    return 0;
}
