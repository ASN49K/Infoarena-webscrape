#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("nim.in" , "r", stdin);
    freopen("nim.out" , "w", stdout);
    int Q , n , x;
    for (scanf("%d", &Q) ; Q; --Q)
    {
        scanf("%d", &n);
        int nr = 0;
        for ( ; n ; --n)
        {
            scanf("%d", &x);
            nr = nr ^ x;
        }
        if (!nr)printf("NU\n");
        else printf("DA\n");
    }

    return 0;
}
