#include <stdio.h>

int main() {
  FILE *fin = fopen( "nim.in", "r" );
  FILE *fout = fopen( "nim.out", "w" );
  int n, i, m, in, sxor, nr;

  fscanf( fin, "%d", &n );
  for ( in = 0; in < n; ++in ) {
    fscanf( fin, "%d", &m );
    sxor = 0;
    for ( i = 0; i < m; ++i ) {
      fscanf( fin, "%d", &nr );
      sxor ^= nr;
    }
    if ( sxor == 0 ) {
      fprintf( fout, "NU\n" );
    } else {
      fprintf( fout, "DA\n" );
    }
  }
  fclose( fin );
  fclose( fout );
  return 0;
}
