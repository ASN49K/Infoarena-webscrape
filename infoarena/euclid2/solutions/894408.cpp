#include <cstdio>
using namespace std;
int t;
int a,b;
int gcd(int a, int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
void citire()
{
    freopen("euclid2.in","r",stdin);
    scanf("%d",&t);
    freopen("euclid2.out","w",stdout);
    for(int i=1;i<=t;++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
}
int main()
{
    citire();
    return 0;
}
