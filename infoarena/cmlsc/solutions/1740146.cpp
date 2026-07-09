#include <fstream>
using namespace std ;

int A[1024] , B[1024] , V[1024];

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void sortare( long &N , long &M , int A[] , int B[] )
{
    long i , j , aux , max; aux=0 ; max = 0 ;

    if ( N > M ) max = N ; else max = M;

    for( i = 1 ; i <= max ; i++ )
     for( j = i ; j <= max ; j++ )
     {
         if ( i && j < N+1 ) if ( A[i] > A[j] ) { aux = A[i] ; A[i] = A[j] ; A[j] = aux ; }
         if ( i && j < M+1 ) if ( B[i] > B[j] ) { aux = B[i] ; B[i] = B[j] ; B[j] = aux ; }
     }

}

int main()
{
  long N , M ;

  in >> N >> M;

  long i , j ;

  for ( i = 1 ; i <= N ; i++ ) in >> A[i] ;
  for ( j = 1 ; j <= M ; j++ ) in >> B[j] ;

  for ( i = 1 ; i <= M+N ; i++ ) V[i]=0;

  sortare( N , M , A , B );

  long nr = 0 ;

   if ( N >= M )
    for ( i = 1 ; i <= M ; i++ )
         for ( j = 1 ; j <= N ; j++ )
           if ( B[i] == A[j] ) { nr++ ; V[nr] = A[j] ; }
   if ( N < M )
    for ( i = 1 ; i <= N ; i++ )
         for ( j = 1 ; j <= M ; j++ )
           if ( A[i] == B[j] ) { nr++ ; V[nr] = B[j] ; }

  out << nr << endl ;

  for ( i = 1 ; i <= nr ; i++ )
    out << V[i] << " " ;

  in.close();
  out.close();

  return 0;
}
