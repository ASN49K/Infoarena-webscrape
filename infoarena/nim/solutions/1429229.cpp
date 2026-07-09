#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, i, j, t;
int s, nr;
int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        scanf("%d", &s);
        for (i = 1; i < n; ++i)
        {
            scanf("%d", &nr);
            s ^= nr;
        }
        if (s) printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
