#include <stdio.h>

int euclid(int a, int b)
{
    if (!b) return(a);
    return euclid(b, a % b);
}

int main()
{
    int a, b;
    
    freopen("euclid2.in", "rt", stdin);
    freopen("euclid2.out", "wt", stdout);

    scanf("%d %d", &a, &b);
    printf("%d", euclid(a,b));

    return(0);
}

