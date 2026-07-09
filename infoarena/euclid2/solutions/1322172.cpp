#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

#define INF (1<<30)
#define mod 666013

using namespace std;
int a, b, t, d;
int bin_gcd(int a, int b)
{
    if(a==0||a==b)
        return b;
    if(b==0)
        return a;

    if(a&1)
    {
        if(b&1)
        {
            if(a>b)
                return bin_gcd((a-b)>>1, b);
            return bin_gcd((b-a)>>1, a);
        }
        return bin_gcd(a, b>>1);
    }
    if(b&1)
        return bin_gcd(a>>1, b);
    return bin_gcd(a>>1, b>>1)<<1;
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &a, &b);
        d=bin_gcd(a, b);
        printf("%d\n", d);
    }
    return 0;
}
