#include <iostream>

using namespace std;


int Gcd(int a,int b)
{
    int result = 1;
    while( true )
    {
        if(a == 0)
            return b * result;
        if(b == 0)
            return a * result;

        while( (a & 1) == 0 && (b & 1) == 0)
        {
            result <<= 1;
            a >>= 1;
            b >>= 1;
        }

        while( (a & 1) == 0 )
            a >>= 1;
        while( (b & 1) == 0 )
            b >>= 1;

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
        printf("%d\n",Gcd(a,b));
    }
    return 0;
}
