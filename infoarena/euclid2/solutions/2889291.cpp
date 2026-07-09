#include <stdio.h>

int numberOfPairs;

int getGreatestCommonDivisor(int a, int b)
{
    if (!b) return a;
    return getGreatestCommonDivisor(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &numberOfPairs);
    while (numberOfPairs--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", getGreatestCommonDivisor(a, b));
    }

    return 0;
}
