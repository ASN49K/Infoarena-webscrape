#include <cstdio>

using namespace std;
int cmmdc1 ( int a , int b )
{
    int r ;
    while ( b )
    {
        r = a % b ;
        a = b ;
        b = r ;
    }
    return a ;
}
int main()
{
    int n , a , b , i ;
    scanf ( "%d" , & n ) ;
    for ( i = 1 ; i <= n ; ++ i )
    {
        scanf ( "%d%d" , & a , & b ) ;
        printf ( "%d\n" , cmmdc1 ( a , b ) ) ;
    }
    return 0;
}
