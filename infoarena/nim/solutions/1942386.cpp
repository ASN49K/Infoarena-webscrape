#include <cstdio>
using namespace std;
int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    int t, n, s, x;
    for(scanf("%d", &t); t > 0; --t)
    {
        s = 0;
        for(scanf("%d", &n); n > 0; --n)
            scanf("%d", &x), s ^= x;
        if (s)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
