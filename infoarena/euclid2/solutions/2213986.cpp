#include <fstream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    ios::sync_with_stdio(false);

    int T;
    scanf("%d", &T);

    int a, b;
    while (T--) {
        scanf("%d %d", &a, &b);

        printf("%d\n", gcd(a, b));
    }

    return 0;
}