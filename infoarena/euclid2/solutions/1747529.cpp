#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int gcd(int a, int b)
{
    return ( b == 0 ) ? a : gcd(b,a%b);
}

int main()
{
    int nrQueries = 0,a,b;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d",&nrQueries);
    while(nrQueries--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
