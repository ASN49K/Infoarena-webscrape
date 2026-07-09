#include <iostream>

using namespace std;

long long greatestCommonDivisor(long long A, long long B)
{
    if (!B)
        return A;
    return greatestCommonDivisor(B, A % B);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int N;
    scanf("%d", &N);
    while (N --) {
        long long A, B;
        scanf("%lld%lld", &A, &B);
        printf("%lld\n", greatestCommonDivisor(A, B));
    }

    return 0;
}
