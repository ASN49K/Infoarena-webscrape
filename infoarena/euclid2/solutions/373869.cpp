#include <stdio.h>

int main()
{
    freopen ("cmmdc.in" , "r" , stdin ) ;
    freopen ("cmmdc.out" , "w" , stdout ) ;
    
    int r , a , b ;
    
    scanf ( "%d%d" , &a , &b) ;
    do
    {
        r=a%b ;    
        a=b ;
        b=r ;
    } while (r) ;
    if ( a>1 )
    printf ( "%d" , a );
    else
    printf ( "0"  ) ; 
    
    return 0;
}
