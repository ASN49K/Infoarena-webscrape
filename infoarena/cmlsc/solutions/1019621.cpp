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

    for ( int i = 0 ; i < N ; i++ )
        f >> A[i] ;

    for ( int i = 0 ; i < M ; i++ )
        f >> B[i] ;


    for( int i = 0 ; i <= N ; i++ )
        for( int j = 0 ; j <= M ; j++ )
            if( A[i] == B[j] )
                D[i][j] = D[i-1][j-1] + 1 ;
            else
                D[i][j] = max( D[i-1][j] , D[i][j-1] );


    for( int i = M + 1 , j = N + 1 ; i ; ){

        if( A[i] == B[j] )
        {
            Sub[C++] = A[i] ;
            i-- ;
            j-- ;

        }else if( D[i-1][j] > D[i][j-1] )
            i--;
         else
            j--;

    }

    g << C << '\n';

    for( ; C-- ; ){

        g << Sub[C] << ' ' ;

    }g << '\n' ;


    return 0;
}
