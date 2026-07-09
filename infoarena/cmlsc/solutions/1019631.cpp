#include <iostream>
#include <fstream>

using namespace std;

const int Nmax = 1024 ;

int A[Nmax];
int B[Nmax];

int Sub[Nmax];

int D[Nmax][Nmax];

int N , M ;
int C ;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");


    f >> N >> M ;

    for ( int i = 1 ; i <= N ; i++ )
        f >> A[i] ;

    for ( int i = 1 ; i <= M ; i++ )
        f >> B[i] ;

    for( int i = 1 ; i <= N ; i++ )
        for( int j = 1 ; j <= M ; j++ )
            if( A[i] == B[j] )
                D[i][j] = D[i-1][j-1] + 1 ;
            else
                D[i][j] = max( D[i-1][j] , D[i][j-1] );


    for( int i = N , j = M ; i ; ){

        if( A[i] == B[j] )
        {
            Sub[++C] = A[i] ;
            i-- ;
            j-- ;

        }else if( D[i-1][j] < D[i][j-1] )
            j--;
         else
            i--;

    }

    cout << C << endl ;

    g << C << '\n';

    for( int i = C ; i > 0 ; i-- ){

        g << Sub[i] << ' ' ;

    }g << '\n' ;


    return 0;
}
