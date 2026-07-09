#include <cstdio>
using namespace std;
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
int n,a,b,k,i;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        k=gcd(a,b);
        printf("%d\n",k);

    }
    return 0;
}
