#include <stdio.h>
int v , w ;
int main()
{
    freopen ("euclid2.in" , "r" , stdin ) ;
    freopen ("euclid2.out" , "w" , stdout ) ;
    
    int n ,k ;
    scanf ("%d" , &n ) ;
        for ( int i=1 ; i<=n ; i++ )
            {
                scanf ("%d" , &v ) ;  
                scanf ("%d" , &w ) ;     
                
                    do
                    {
                        k=v%w ; 
                        v=w ;
                        w=k  ;    
                    } while (k) ;
                
                
                printf ("%d\n" , v) ;
            }
    return 0 ;
}
