#include <cstdio>

using namespace std;

int t,a,b,r;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d",&t);
    for(;t;t--)
    {
        scanf("%d%d",&a,&b);
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        printf("%d\n",b);
    }
    return 0;
}
