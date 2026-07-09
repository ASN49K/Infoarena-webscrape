#include <bits/stdc++.h>

using namespace std;

int Gcd(int a,int b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;

    if( (a & 1) == 0 && (b & 1) == 0)
        return 2 * Gcd(a >> 1, b >> 1);

    if( (a & 1) == 0 )
        return Gcd(a >> 1, b);
    if( (b & 1) == 0 )
        return Gcd(a, b >> 1);

    if(a > b)
        return Gcd(a-b, b);
    return Gcd(a, b-a);
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
