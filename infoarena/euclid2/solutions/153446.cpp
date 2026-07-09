#include <stdio.h>
#include <assert.h>

int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    assert(1 <= T && T <= 100000);	
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        assert(2 <= A && 2 <= B && A <= 2000000000 && B <= 2000000000);
        printf("%d\n", gcd(A, B));
    }        

    return 0;
}

