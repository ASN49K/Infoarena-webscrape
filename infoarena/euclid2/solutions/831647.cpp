#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a == b)
        return a;
    if(~a&1)
        if(~b&1)
            return gcd(a>>1,b>>1)<<1;
        else
            return gcd(a>>1,b);
    if(~b&1)
        return gcd(a,b>>1);
    if(a > b)
        return gcd((a-b)>>1,b);
    return gcd((b-a)>>1,a);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T;
    int a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
    }

}
