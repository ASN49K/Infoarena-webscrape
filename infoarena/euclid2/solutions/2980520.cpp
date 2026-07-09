#include <iostream>
#include <cstdio>

int main ()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n,a,b,r;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
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
