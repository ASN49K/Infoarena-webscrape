#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

#define INF ( (1 << 30) - 1 + (1 << 30) )
#define mod 666013

using namespace std;

int t, x, y, d;

int binary_gcd(int x, int y)
{
    if(x == 0 || x == y)
        return y;
    if(y == 0)
        return x;

    if(x & 1)
    {
        if(y & 1)
            return binary_gcd( abs(y - x) >> 1, x);
        return binary_gcd(x, y >> 1);
    }
    else
    {
        if(y & 1)
            return binary_gcd(x >> 1, y);
        return (binary_gcd(x >> 1, y >> 1) << 1);
    }
    return -1;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &x, &y);
        d = binary_gcd(x, y);
        printf("%d\n", d);
    }
    return 0;
}
