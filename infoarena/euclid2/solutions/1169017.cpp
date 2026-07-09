#include <stdio.h>
long x,y,n;
using namespace std;
inline long cmmdc(long x,long y)
{
    if (x==y)
        return x;
    if (!x||!y)
        return 0;
    if (x>y)
        return cmmdc(x%y,y);
    else
        return cmmdc(x,y%x);
}
int main()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    scanf ("%ld",&n);
    for (long i=1;i<=n;i++)
    {
        scanf ("%ld %ld",&x,&y);
        printf ("%ld\n",cmmdc(x,y));
    }
    return 0;
}
