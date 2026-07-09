#include <stdio.h>
using namespace std;
int shl,tmp,i,x,n,y;
bool eu,ev;
int binary_gcd(int u, int v)
{
  shl = 0;

  while ( u && v && u!=v ) {
    eu = !(u & 1);
    ev = !(v & 1);

    if ( eu && ev ) {
      ++shl;
      u >>= 1;
      v >>= 1;
    }
    else if ( eu && !ev ) u >>= 1;
    else if ( !eu && ev ) v >>= 1;
    else if ( u>=v ) u = (u-v)>>1;
    else {
      tmp = u;
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
    for (i=1;i<=n;i++)
    {
        scanf ("%d %d",&x,&y);
        printf ("%ld\n",binary_gcd(x,y));
    }
    return 0;
}
