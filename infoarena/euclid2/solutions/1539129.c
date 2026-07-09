#include <stdio.h>

//algoritmul lui Euclid implementat recursiv cu impartiri
int cmmdc( int a , int b ) {
  if( a % b == 0 )
    return b;
  else
    return cmmdc( b , a % b );
}

int main(){
  int n , i , a , b;
  FILE *fin = fopen( "euclid2.in" , "r" );
  FILE *fout = fopen( "euclid2.out" , "w" );

  fscanf( fin , "%d" , &n );
  for( i = 0 ; i < n ; i++ ) {
    fscanf( fin , "%d%d" , &a , &b );
    fprintf( fout , "%d\n" , cmmdc( a , b ) );
  }

  fclose( fin );
  fclose( fout );
  return 0;
}
