#include<cstdio>
using namespace std;
long t;
long long a,b;
long long cmmdc(long long x,long long y)
{
    long long r=x%y;
    while (r)
        {
            x=y;y=r;
            r=x%y;
        }
    return y;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%ld",&t);
    for (long i=1;i<=t;i++)
        {
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",cmmdc(a,b));
        }
    return 0;
}
