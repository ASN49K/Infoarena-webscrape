#include <cstdio>
using namespace std;
inline int gcd(int a,int b)
{
    int r;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
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
