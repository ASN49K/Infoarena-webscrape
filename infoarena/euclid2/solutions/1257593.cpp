#include <iostream>
#include <cstdio>

using namespace std;

long long n,i,x,y,r;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%lld",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%lld%lld",&x,&y);
        r=0;
        do
        {
          r=x%y;
          x=y;
          y=r;
        }
        while (r>0);
        printf("%lld\n",x);
    }
    return 0;
}
