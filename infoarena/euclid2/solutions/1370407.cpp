#include <cstdio>

using namespace std;

int main()
{
    long long T,a,b,r;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%lld",&T);
    while(T > 0)
    {
        --T;
        scanf("%lld%lld",&a,&b);
        while(a > 0)
        {
            r = b % a;
            b = a;
            a = r;
        }
        printf("%lld\n",b);
    }
return 0;
}
