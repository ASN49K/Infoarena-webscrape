#include <cstdio>

using namespace std;

int cmmdc( int a , int b )
{
    if ( b )
        return cmmdc( b , a % b ) ;
    else
        return a ;
}

int main()
{
    freopen( "euclid2.in" , "r" , stdin ) ;
    freopen( "euclid2.out" , "w" , stdout ) ;

    int t , a , b ;
    scanf( "%d" , &t ) ;

    for ( ; t ; t-- )
    {
        scanf( "%d %d" , &a , &b ) ;
        printf( "%d\n" , cmmdc(a,b) ) ;
    }

    return 0;
}
