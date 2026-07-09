#include <iostream>
#define FIN "euclid2.in"
#define FOUT "euclid2.out"

int main()
{
    int t,x,y;
    freopen ( FIN , "r" , stdin );
    freopen ( FOUT , "w" , stdout );
    scanf ( "%d" , &t );
    while ( t-- )
    {
        scanf ( "%d %d" , &x , &y );
        while ( x && y ) if (x>y) x%=y; else y%=x;
        printf ( "%d\n" , (x)?(x):(y) );
    }
    fclose ( stdin );
    fclose ( stdout );
    return 0;
}
