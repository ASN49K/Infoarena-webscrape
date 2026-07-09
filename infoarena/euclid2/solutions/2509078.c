#include <stdio.h>

int main() {
  FILE *fin = fopen( "euclid2.in", "r" );
  FILE *fout = fopen( "euclid2.out", "w" );
  int q, i, r, a, b;

  fscanf( fin, "%d", &q );
  for ( i = 0; i < q; ++i ) {
    fscanf( fin, "%d%d", &a, &b );
    while ( b > 0 ) {
      r = a % b;
      a = b;
      b = r;
    }
    fprintf( fout, "%d\n", a );
  }
  fclose( fin );
  fclose( fout );
  return 0;
}
