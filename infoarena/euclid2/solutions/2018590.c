#include <stdio.h>

int T, a , b , i;

int euclid( int a, int b ){
     int r;

     while( b ){
        r = a % b;
        a = b;
        b = r;
     }

     return a;
}

int main(){

    freopen( "euclid2.in" , "r" , stdin );
    freopen( "euclid2.out" , "w" , stdout );

    scanf( "%d" , &T );
    for( i = 1 ;  i <= T ; i++ ){
        scanf( "%d %d" , &a , &b );
        printf( "%d\n" , euclid( a , b ) );
    }

    return 0;
}
