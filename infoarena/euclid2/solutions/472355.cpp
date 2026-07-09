# include <algorithm>
using namespace std;

int T ;

inline int modulo ( int a, int b ) {
    return a & b ;
}

inline int euclid ( int a, int b ) {
    int sol;

    if ( a == 0 || b == 0 )
        return a | b;

    for (sol = 0; modulo ( a | b, 1 ) == 0; ++sol) {
        a >>= 1;
        b >>= 1;
    }

    for ( ; modulo ( a, 1 ) == 0 ;  a >>= 1 ) ;

    for ( ; b ; b >>= 1 ) {
        for ( ; modulo ( b, 1 ) == 0 ; b >>= 1 ) ;

        if ( a < b ) {
            b -= a;
        } else {
            swap ( a, b ) , b -= a;
        }
    }

    return a << sol;
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
