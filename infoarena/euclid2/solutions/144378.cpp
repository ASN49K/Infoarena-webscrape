#include <stdio.h>

#define in "euclid2.in"
#define out "euclid2.out"

int GCD(int a,int b) { if ( !b ) return a; return GCD(b, a%b); }
int X, Y;

int main()
{
    freopen( in, "r", stdin );
    freopen( out, "w", stdout );
    
    scanf( "%d%d", &X, &Y );
    printf( "%d\n", GCD(X,Y) );
    
    return 0;
}
