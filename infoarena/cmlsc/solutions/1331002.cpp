#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int Solutie[ 1025 ][ 1025 ] ;
int main()
{
    ifstream f ( "cmlsc.in" ) ;
    ofstream g ( "cmlsc.out" ) ;

    int Lungime1 , Lungime2 , Sir1 [ 1025 ] , Sir2 [ 1025 ] ;

    f >> Lungime1 >> Lungime2 ;
    for ( int i = 1 ; i <= Lungime1 ; i++ )
        f >> Sir1 [ i ] ;

    for ( int i = 1 ; i <= Lungime2 ; i++ )
        f >> Sir2 [ i ] ;

    for ( int i = 1 ; i <= Lungime1 ; i++ )
        for ( int j = 1 ; j <= Lungime2 ; j++ )
            if ( Sir1 [ i ] == Sir2 [ j ] )
                Solutie [ i ][ j ] = Solutie [ i - 1 ][ j - 1 ] + 1 ;

                else
                    Solutie [ i ][ j ] = max ( Solutie [ i - 1 ][ j ] , Solutie [ i ][ j - 1 ] ) ;

        g << Solutie [ Lungime1 ][ Lungime2 ] << endl ;
        int SubSir[ 1025 ] , contor = 0  ;

        for ( int i = 1 ; i <= Lungime1 ; i++ )
            for ( int j = 1 ; j <= Lungime2 ; j++ )
                if ( Solutie[ i ][ j ] > contor )
                    {
                            ++contor ;
                            SubSir [ contor ] = Sir1 [ i ] ;
                    }

        for ( int i = 1 ; i <= contor ; i++ )
            g << SubSir [ i ] << " " ;

    return 0;
}
