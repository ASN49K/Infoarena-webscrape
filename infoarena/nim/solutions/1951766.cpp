#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int t, n, x, sum;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        sum = 0;
        while(n--)
        {
            scanf("%d", &x);
            sum ^= x;
        }

        if(!sum) printf("NU\n");
        else printf("DA\n");
    }

    return 0;
}
