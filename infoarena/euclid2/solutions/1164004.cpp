#include <cstdio>

int n,a,b;

int euclid(int x, int y)
{
    if (!y)
        return x;
    return euclid(y,x%y);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a, b));
    }

    return 0;
}
