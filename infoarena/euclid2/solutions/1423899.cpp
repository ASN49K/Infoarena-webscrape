#include <iostream>

using namespace std;

int T, x, y;

int gcd(int a, int b)
{
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&x, &y);
        printf("%d\n",gcd(x, y));
    }
    return 0;
}
