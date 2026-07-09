#include <cstdio>

using namespace std;
long long a,b,T,r;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%lld",&T);
    while(T>0)
    {
        scanf("%lld%lld",&a,&b);
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        printf("%lld\n",a);
        --T;
    }
    return 0;
}
