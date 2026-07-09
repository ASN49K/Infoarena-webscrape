#include <stdio.h>

int main() {
  FILE *fin = fopen( "euclid2.in", "r" );
  FILE *fout = fopen( "euclid2.out", "w" );

  int a, b;
  fscanf( fin, "%d%d", &a, &b );

  int t;
  while( b ){
    t = a % b;
    a = b;
    b = t;
  }

  fprintf( fout, "%d\n", a );

  fclose( fin );
  fclose( fout );
  return 0;
}
