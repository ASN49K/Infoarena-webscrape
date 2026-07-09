#include <stdio.h>
long x,y,n;
using namespace std;
long gcd(long a, long b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
int main()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    scanf ("%ld",&n);
    for (long i=1;i<=n;i++)
    {
        scanf ("%ld %ld",&x,&y);
        printf ("%ld\n",gcd(x,y));
    }
    return 0;
}
