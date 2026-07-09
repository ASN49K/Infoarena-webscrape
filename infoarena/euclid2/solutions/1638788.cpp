#include <cstdio>

using namespace std;

int gcd(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int t,a,b;
    for(scanf("%d",&t);t;t--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
