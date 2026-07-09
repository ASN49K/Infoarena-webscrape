# include <cstdio>

int T ;

int euclid ( int a, int b ) {
    while ( b ) {
        int r = a % b ;
        a = b ;
        b = r ;
    }

    return a ;
}

int main () {
    freopen ( "euclid2.in", "r", stdin ) ;
    freopen ( "euclid2.out", "w", stdout ) ;

    for ( scanf ( "%d", &T ) ; T ; --T ) {
        int A, B ;
        scanf ( "%d %d", &A, &B ) ;
        printf ( "%d\n", euclid ( A, B ) ) ;
    }

    return 0;
}
