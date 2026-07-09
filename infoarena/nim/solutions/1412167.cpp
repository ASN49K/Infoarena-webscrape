#include <bits/stdc++.h>

using namespace std;
int n, t, x, i, sum;
int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    scanf("%d", &t);
    for(; t; t--)
    {
        scanf("%d", &n);
        sum = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            sum ^= x;
        }
        if(sum)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
