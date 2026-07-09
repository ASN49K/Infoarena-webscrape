#include <cstdio>
using namespace std;
inline int gcd(const int a,const int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t,a ,b;
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%d %d\n",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
