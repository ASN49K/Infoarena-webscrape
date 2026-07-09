#include <cstdio>

using namespace std;

int T, res;

void Euclid(int a, int b)
{
    if (!b)
    {
        res = a;
        return;
    }

    Euclid(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);

    int a, b;

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &a, &b);
        Euclid(a, b)
        printf("%d\n", res);
    }

    return 0;
}
