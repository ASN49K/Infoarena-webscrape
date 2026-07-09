#include <bits/stdc++.h>

using namespace std;

int T , n , x , crt , i;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

    for (scanf("%d", &T); T ; --T)
    {
        scanf("%d", &n); crt = 0;
        for (i = 1; i <= n; ++i)
            scanf("%d", &x),
            crt ^= x;
        if (crt == 0) printf("NU\n"); else printf("DA\n");
    }

    return 0;
}
