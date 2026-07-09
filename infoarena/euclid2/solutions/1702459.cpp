#include <cstdio>
using namespace std;
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int t, a, b, r;
    scanf("%d", &t);
    for (register int i = 1; i <= t; ++i)
    {
        scanf("%d %d", &a, &b);
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        printf("%d\n", a);
    }

    return 0;
}
