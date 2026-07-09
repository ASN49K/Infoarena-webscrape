#include <iostream>

using namespace std;

int euclid(int a, int b)
{
    int gcd = 1;
    while(1){
        if(a == 0)
            return gcd * b;
        if(b == 0)
            return gcd * a;
        while((a & 1) + (b & 1) == 0)
        {
            a >>= 1;
            b >>= 1;
            gcd <<= 1;
            continue;
        }

        while((a & 1) == 0)
        {
            a >>= 1;
            continue;
        }
        while((b & 1) == 0)
        {
            b >>= 1;
            continue;
        }
        if(a > b)
            a -= b;
        else
            b -= a;
    }
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int T,a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    return 0;
}
