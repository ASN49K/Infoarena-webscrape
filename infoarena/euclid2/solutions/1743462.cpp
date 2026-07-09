#include <cstdio>

#define in "euclid2.in"
#define out "euclid2.out"

using namespace std;
int t, a, b;

int gcd(const int &x, const int &y)
{
    if(x == 0) return y;
    return gcd(y%x, x);
}

int main()
{
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
    scanf("%d", &t);
    for( ; t; --t)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
