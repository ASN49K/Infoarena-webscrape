#include <stdio.h>
long x,y,n;
using namespace std;
int binary_gcd(int u, int v)
{
  int shl = 0;

  while ( u && v && u!=v ) {
    bool eu = !(u & 1);
    bool ev = !(v & 1);

    if ( eu && ev ) {
      ++shl;
      u >>= 1;
      v >>= 1;
    }
    else if ( eu && !ev ) u >>= 1;
    else if ( !eu && ev ) v >>= 1;
    else if ( u>=v ) u = (u-v)>>1;
    else {
      int tmp = u;
      u = (v-u)>>1;
      v = tmp;
    }
  }

  return !u? v<<shl : u<<shl;
}
int main()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    scanf ("%ld",&n);
    for (long i=1;i<=n;i++)
    {
        scanf ("%ld %ld",&x,&y);
        printf ("%ld\n",binary_gcd(x,y));
    }
    return 0;
}
