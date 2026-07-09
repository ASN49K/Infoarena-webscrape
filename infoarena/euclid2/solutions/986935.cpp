#include <cstdio>
using namespace std;

long long cmmdc(long long a,long long b)
{
    if(b==0) return a;
    else cmmdc(b,a%b);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    long long a,b,r;
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",cmmdc(a,b));
    }
    return 0;
}
