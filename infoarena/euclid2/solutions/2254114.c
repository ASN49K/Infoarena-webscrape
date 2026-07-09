#include <stdio.h>

int main(void)
{
    freopen("euclid.in", "r", stdin);
    freopen("euclid.out", "w", stdout);

    int a, b, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &a, &b);
        int r;
        while(b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        printf("%d\n", a);
    }
    return 0;
}
