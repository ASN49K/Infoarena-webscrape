#include <iostream>
#include <cstdio>

using namespace std;

int cmmdc( int a , int b ) ;

int main()
{
    int n , nr1 , nr2 ;
    freopen( "euclid2.in" , "r" , stdin ) ;
    freopen( "euclid2.out" , "w" , stdout ) ;
    scanf( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i ++ )
    {
        scanf( "%d %d" , &nr1 , &nr2 ) ;
        printf( "%d\n" , cmmdc( nr1 , nr2 ) ) ;
    }
    return 0;
}

int cmmdc( int a , int b )
{
    int r = 0 ;
    while (b)
    {
        r = a % b ;
        a = b ;
        b = r ;
    }
    return a ;
}
