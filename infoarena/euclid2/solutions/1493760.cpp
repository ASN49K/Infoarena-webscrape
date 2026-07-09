#include <cstdio>
#include <algorithm>

using namespace std;

int     euclid(int a, int b)
{
    if (b)
        return euclid(b, a % b);
    else
        return a;
}

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
        if (a > b) swap(a, b);
        printf("%d\n", euclid(a, b));
    }
    return 0;
}
