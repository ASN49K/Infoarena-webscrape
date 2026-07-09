/*
Colectia personala de operatii pe numere mari - C++ ( classes )
Implementate de Robert Simoiu
Incluzand extragerea radacinii patrate cu oricate zecimale
*/

# include <cmath>
# include <cstdio>
# include <cstring>
# include <vector>
using namespace std ;

/*
precizare :
1. Daca vreti sa faceti a = b + c, in loc de a += b , trebuie in loc de void operator += ( ... )
sa faceti Mare operator + ( ... ) , si sa returnati un vector Mare ( exemplu prima functie, Mare operator + ( Mare& ) )
2. Pentru comparari, se poate face usor > si >=, doar schimband returnurile ( fals cu adevarat, si invers ), dar
e de preferabil ca a > b sa se faca ca si b < a ( pentru a nu mai fi nevoie de introducerea unei noi comparari )
*/

# define MAX 1000 // numarul de cifre
# define verf( X, i ) ( i <= X[0] ? X[i] : 0 )
# define A ( *this )

class Mare : protected vector < int > {
public :
    Mare ( ) ;
    Mare ( int ) ;
    Mare operator + ( Mare& ) ;
    int operator % ( int ) ;
    Mare operator % ( Mare& ) ;
    void operator = ( char* ) ;
    void operator += ( Mare& ) ;
    void operator *= ( int ) ;
    void operator *= ( Mare& ) ;
    void operator -= ( Mare& ) ;
    bool operator < ( Mare& ) ;
    bool operator <= ( Mare& ) ;
    void operator <<= ( int ) ;
    void operator >>= ( int ) ;
    void operator /= ( int ) ;
    void operator /= ( Mare& ) ;
    void radical_normal ( Mare&, int ) ;
    void radical_cb ( Mare& ) ;
    void afis ( void ) ;
    void afis_rad ( int ) ;
    bool af ( void ) ;
} ;

Mare :: Mare () { // A = 0
    this -> resize ( MAX ) ;
}

Mare :: Mare ( int X ) { // A = X
    this -> resize ( MAX ) ;
    for ( A[0] = 0; X ; X /= 10 ) {
        A[ ++A[0] ] = X % 10 ;
    }
}

Mare Mare :: operator + ( Mare &B ) { // C = A + B
    int i, t = 0;
    Mare C ;
    for ( i = 1; i <= A[0] || i <= B[0] || t; ++i, t /= 10 )
        C[i] = ( t += verf ( A, i ) + verf ( B, i ) ) % 10 ;
    C[0] = i - 1;

    return C ;
}

int Mare :: operator % ( int B ) { // A % B
    int i, t = 0;
    for (i = A[0]; i > 0; i--)
        t = ( t * 10 + A[i] ) % B ;
    return t ;
}

void Mare :: operator += ( Mare &B ) { // A += B
    int i, t = 0;
    for ( i = 1; i <= A[0] || i <= B[0] || t; ++i, t /= 10 )
        A[i] = ( t += verf ( A, i ) + verf ( B, i ) ) % 10 ;
    A[0] = i - 1;
}

void Mare :: operator *= ( int B ) { // A *= B
    int i, t = 0;
    for ( i = 1; i <= A[0] || t; ++i, t /= 10 )
        A[i] = ( t += verf ( A, i ) * B ) % 10 ;
    A[0] = i - 1;
}

void Mare :: operator -= ( Mare &B ) { // A -= B, ∀ A ≥ B
    int t = 0;
    for ( int i = 1; i <= A[0]; ++i ) {
        t = ( A[i] -= verf ( B, i ) + t ) < 0 ;
        A[i] += t * 10 ;
    }
    for ( ; A[0] > 1 && !A[A[0]]; --A[0] ) ;
}


bool Mare :: operator < ( Mare &B ) { // A < B ?
    for ( ; A[0] && !A[ A[0] ] ; --A[0] ) ;
    for ( ; B[0] && !B[ B[0] ] ; --B[0] ) ;

    if ( A[0] < B[0] ) return true;
    else if ( A[0] > B[0] ) return false;

    for ( int i = A[0]; i > 0; --i )
        if ( A[i] < B[i] ) return true;
        else if ( A[i] > B[i] ) return false;

    return false;
}

bool Mare :: operator <= ( Mare &B ) { // A <= B ?
    for ( ; A[0] && !A[ A[0] ] ; --A[0] ) ;
    for ( ; B[0] && !B[ B[0] ] ; --B[0] ) ;

    if ( A[0] < B[0] ) return true;
    else if ( A[0] > B[0] ) return false;

    for ( int i = A[0]; i > 0; --i )
        if ( A[i] < B[i] ) return true;
        else if ( A[i] > B[i] ) return false;

    return true;
}


void Mare :: operator *= ( Mare &B ) { // A *= B
    int i, j, t ;
    Mare C ;
    for ( i = 1; i <= A[0]; ++i ) {
        for (t = 0, j = 1; j <= B[0] || t; j++, t /= 10)
            C[i + j - 1] = ( t += C[i + j - 1] + verf ( A, i ) * verf ( B, j ) ) % 10;
        if ( i + j - 2 > C[0] )
            C[0] = i + j - 2;
    }

    A = C ;
}

void Mare :: operator <<= ( int Count ) { // A *= ( Count * 10 )
    for ( int i = A[0]; i ; --i )
        A[i + Count] = A[i] ;
    for ( int i = 1; i <= Count; ++i )
        A[i] = 0 ;

    A[0] += Count ;
}

void Mare :: operator >>= ( int Count ) { // A /= ( Count * 10 )
    for ( int i = Count + 1; i <= A[0]; ++i ) {
        A[i - Count] = A[i] ;
    }

    A[0] -= Count ;
}


void Mare :: operator /= ( int B ) { // A /= B
    int t = 0;
    for ( int i = A[0]; i > 0; i--, t %= B )
        A[i] = ( t = t * 10 + A[i] ) / B ;
    for ( ; A[0] > 1 && !A[ A[0] ]; --A[0] ) ;
}

void Mare :: operator /= ( Mare &B ) { // A /= B
    Mare R ;

    for ( int i = A[0]; i ; --i ) {
        R <<= 1, R[1] = A[i] ;

        for ( A[i] = 0; B <= R ; ++A[i], R -= B ) ;
    }

    for ( ; !A[ A[0] ] && A[0] > 1 ; --A[0] ) ;
}

Mare Mare :: operator % ( Mare &B ) { // A % B
    Mare C, R ;

    for ( int i = A[0]; i ; --i ) {
        R <<= 1, R[1] = A[i] ;

        for ( C[i] = 0; B <= R ; ++C[i], R -= B ) ;
    }

    return R ;
}

void Mare :: radical_cb ( Mare &B ) { // B = sqrt ( A ) ; doar parte intreaga
    Mare cnt, X ;

    for ( cnt = 1; cnt < A; cnt *= 2 ) ;

    for ( B[0] = 1 ; ! ( cnt[1] == 0 && cnt[0] == 1 ) ; cnt /= 2 ) {
        X = cnt, X += B, X *= X ;
        if ( X <= A )
            B += cnt ;
    }
}

void Mare :: radical_normal ( Mare &B, int nrzecimale ) {
    int AUX = 0, i, j = 1 ;
    Mare C, D, E, F, U ( 9 ), Z ( 1 ) ;

    if ( A[0] & 1 ) AUX = A[ A[0] ], i = A[0] - 1;
    else AUX = A[A[0]] * 10 + A[ A[0] - 1 ], i = A[0] - 2;

    int aux = static_cast < int > ( sqrt ( AUX ) ) ;

    B = aux ;

    if ( A[0] > 2 ) {
        AUX -= aux * aux;

        E = AUX, E <<= 1, F = A[i], E += F ;

        E <<= 1, F = A[i - 1], E += F ;

        C = E, F = B, F *= 2, E = F ;

        D = C, D >>= 1, D /= E ;

        if ( U < D ) {
            D = 9 ;
        }

        E <<= 1, E += D, E *= D ;

        while ( C < E )
            D -= Z, F = B, F *= 2, E = F, E <<= 1, E += D, E *= D ;


        C -= E ;

        B <<= 1, B += D ;
    } else {
        C = AUX - ( aux * aux ) ;
    }

    for ( i = i - 2; i > 0 || j <= nrzecimale ; i -= 2 ) {
        if ( i > 0 ) {
            E = A[i], F = 0, F <<= 1, F += E ;
            E = A[i - 1], F <<= 1, F += E ;
        } else {
            ++j, F = 0 ;
        }
        C <<= 2, C += F, F = B, F *= 2, E = F ;
        D = C, D >>= 1, D /= E ;

        if ( U < D ) {
            D = 9 ;
        }

        E <<= 1, E += D, E *= D ;

        while ( C < E )
            D -= Z, F = B, F *= 2, E = F, E <<= 1, E += D, E *= D ;

        C -= E ;

        B <<= 1, B += D ;
    }
}

void Mare :: operator = ( char* B ) {
    A[0] = strlen ( B );
    for ( int i = A[0]; i ; --i )
        A[i] = B[A[0] - i] - '0' ;
}

void Mare :: afis ( void ) {
    for ( int i = A[0]; i ; --i ) {
        printf ( "%d", A[i] ) ;
    }
    printf ( "\n" ) ;
}

void Mare :: afis_rad ( int nrzecimale ) { // afisarea radicalului
    for ( int i = A[0] ; i > nrzecimale ; --i )
        printf ( "%d", A[i] ) ;
    printf ( "." ) ;
    for ( int i = nrzecimale ; i ; --i ) {
        printf ( "%d", A[i] ) ;
    }
}

bool Mare :: af ( void ) {
    return  A[1] != 0 || A[0] != 0 ;
}

# undef A

int T ;
char A[12], B[12] ;
Mare X, Y, Z ;

inline void euclid ( Mare A, Mare B, Mare &C ) {
    while ( B.af () ) {
        Mare R = A % B ;
        A = B ;
        B = R ;
    }
    C = A ;
}

int main ( void ) {
    freopen ( "euclid2.in", "r", stdin ) ;
    freopen ( "euclid2.out", "w", stdout ) ;
    for ( scanf ( "%d", &T ) ; T ; --T ) {
        scanf ( "%s %s", A, B ) ;
        X = A, Y = B ;
        euclid ( X, Y, Z ) ;
        Z.afis () ;
    }
}

