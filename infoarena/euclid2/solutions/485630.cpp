# include <algorithm>
using namespace std;

int T ;

inline int euclid ( int A, int B ) {
    while ( B ) {
        int R = A % B ;
        A = B ;
        B = R ;
    }

    return A ;
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
