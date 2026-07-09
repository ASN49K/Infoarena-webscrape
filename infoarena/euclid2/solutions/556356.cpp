# include <fstream>

int A, B, T ;

inline int euclid ( int A, int B ) {
    return B ? euclid ( B, A % B ) : A ;
}

int main ( void ) {
    std :: ifstream f ( "euclid2.in" ) ;
    std :: ofstream g ( "euclid2.out" ) ;

    for ( f >> T ; T ; --T ) {
        f >> A >> B ;
        g << euclid ( A, B ) << '\n' ;
    }
}
