# include <cstdio>

int A, B, T ;

inline int euclid ( int A, int B ) {
    return B ? euclid ( B, A % B ) : A ;
}

int main ( void ) {
    freopen ( "euclid2.in", "r", stdin ) ;
    freopen ( "euclid2.out", "w", stdout ) ;

    for ( scanf ( "%d", &T ) ; T ; --T ) {
        scanf ( "%d %d", &A, &B ) ;
        printf ( "%d\n", euclid ( A, B ) ) ;
    }
}
