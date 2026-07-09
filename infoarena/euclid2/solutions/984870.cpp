#include <cstdio>

using namespace std;
int i, n, x, y;

inline int gcd(int x, int y)
{
    int r=x%y;
    while(r)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    for(i=1;i<=n;++i)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", gcd(x, y));
    }
    return 0;
}
