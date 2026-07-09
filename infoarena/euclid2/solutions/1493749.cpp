#include <cstdio>

int     main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    int     t;
    int     a, b;
    
    scanf("%d", &t);
    for (int i = 0; i < t; ++ i)
    {
        scanf("%d %d", &a, &b);
        while (a != b)
        {
            if (a > b)
                a -= b;
            else
                b -= a;
        }
        printf("%d\n", a);
    }
    return 0;
}
