#include <cstdio>
using namespace std;
long long T,i,a[100],b[100],r;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
        scanf("%lld %lld",&a[i],&b[i]);
    for(i=1;i<=T;i++)
    {
            while(a[i]%b[i]!=0)
            {
                r=a[i]%b[i];
                a[i]=b[i];
                b[i]=r;
            }
            printf("%lld\n",b[i]);
    }
    return 0;
}
