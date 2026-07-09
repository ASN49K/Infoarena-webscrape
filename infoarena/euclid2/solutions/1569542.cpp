#include <cstdio>
long long int T,a,b;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%lld",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%lld %lld",&a,&b);
        long r;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        printf("%lld\n",a);
    }
    return 0;
}
