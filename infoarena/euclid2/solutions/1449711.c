#include <stdio.h>

void euclid(int a, int b, int *d)
{
    if (b == 0) {
        *d = a;
    } else
        euclid(b, a % b, d);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int a,b,d;
    int t;
    scanf("%d",&t);
    for(;t;--t)
    {
        scanf("%d %d",&a,&b);
        euclid(a,b,&d);
        printf("%d\n",d);
    }

    return 0;
}
