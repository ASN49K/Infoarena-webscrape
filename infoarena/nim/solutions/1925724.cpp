#include <cstdio>
#include <algorithm>

using namespace std;

int main ()
{
    freopen ("nim.in", "r", stdin);
    freopen ("nim.out", "w", stdout);

    int t;
    scanf ("%d", &t);

    for (; t; --t)
    {
        int n;
        scanf ("%d", &n);

        int x = 0;
        for (int i = 1; i <= n; ++i)
        {
            int a;
            scanf ("%d", &a);

            x ^= a;
        }

        if (!x) printf ("NU\n");
        else printf ("DA\n");
    }

    return 0;
}
