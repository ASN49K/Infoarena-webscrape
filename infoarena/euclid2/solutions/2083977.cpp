#include <cstdio>

using namespace std;

int main()
{
    freopen( "euclid2.in", "r", stdin );
    freopen( "euclid2.out", "w", stdout );

    int n, a, b, r;

    scanf( "%d", &n );

    while( n )
    {
        scanf( "%d%d", &a, &b );

        while( b )
        {
            r=a%b;
            a=b;
            b=r;
        }

        printf( "%d", a );

        n--;
    }

    return 0;
}
