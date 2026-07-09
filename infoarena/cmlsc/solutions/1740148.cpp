#include <fstream>
using namespace std ;

int A[1025] , B[1025] , V[1025];

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void sortare( int &N , int &M , int A[] , int B[] )
{
    int i , j , aux , max;

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
  int N , M ;

  in >> N >> M;

  int i , j ;

  for ( i = 1 ; i <= N ; i++ ) in >> A[i] ;
  for ( j = 1 ; j <= M ; j++ ) in >> B[j] ;

  for ( i = 1 ; i <= M+N ; i++ ) V[i]=0;

  sortare( N , M , A , B );

  int nr = 0 ;

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
