#include <stdio.h>
int gcd (int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T, A, B;
    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }
    return 0;
}
