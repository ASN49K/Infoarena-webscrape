#include <fstream>
using namespace std ;

int A[1025] , B[1025] ;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main()
{
    int N , M ;

    in >> N >> M;

    int i , j , aux ;

    for ( i = 1 ; i <= N ; i++ ) in >> A[i] ;

    for ( j = 1 ; j <= M ; j++ ) in >> B[j] ;

    for( i = 1 ; i <= N ; i++ )
     for( j = i ; j <= N ; j++ )
      if ( A[i] > A[j] ) { aux = A[i] ; A[i] = A[j] ; A[j] = aux ; }

    for( i = 1 ; i <= M ; i++ )
     for( j = i ; j <= M ; j++ )
      if ( B[i] > B[j] ) { aux = B[i] ; B[i] = B[j] ; B[j] = aux ; }

    int nr = 0 ;

    for ( i = 1 ; i <= N ; i++ )
     for ( j = 1 ; j <= M ; j++ )
           if ( B[j] == A[i] ) nr++ ;

    out << nr << endl ;

    for ( i = 1 ; i <= N ; i++ )
     for ( j = 1 ; j <= M ; j++ )
           if ( B[j] == A[i] ) out << B[j] << " " ;

    in.close();
    out.close();

    return 0;
}
