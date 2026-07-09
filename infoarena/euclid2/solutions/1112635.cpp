#include <cstdio>
using namespace std;

int t, a, b;

int gcd(int, int);

int main(int argc, char *argv[])
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &t);

    for (; t; --t) {
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }

    return 0;
}

int gcd(int a, int b)
{
    if (!b)
        return a;
    else
        return gcd(b, a % b);
}
