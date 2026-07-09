#include <cstdio>
using namespace std;

int main()
{

    int n, a, b, r;

    freopen( "euclid2.in", "r", stdin );
    freopen( "euclid2.out", "w", stdout );

    scanf( "%d", &n );

    for( int i = 1; i <= n; i++ ) {

        scanf( "%d %d", &a, &b );

        for( r = a%b; r != 0; a=b, b=r, r=a%b );

        printf( "%d\n", b );

    }

    return 0;
}
