#include <cstdio>

using namespace std;
int i, n, x, y;

int gcd(int x, int y)
{
    if(x==y)
        return x;
    if(x==0)
        return y;
    if(y==0)
        return x;
    if(~y&1)
        if(~x&1)
            return gcd(x>>1, y>>1)<<1;
        else
            return gcd(x, y>>1);
    if(~x&1)
        return gcd(x>>1, y);
    if(x>y)
        return gcd((x-y)>>1, y);
    else
        return gcd((y-x)>>1, x);

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
