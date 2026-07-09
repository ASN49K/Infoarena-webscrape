#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int A, B;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }
}
