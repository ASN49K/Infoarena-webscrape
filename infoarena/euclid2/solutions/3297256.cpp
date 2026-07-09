#include <stdio.h>

int main() {
  FILE *fin = fopen( "euclid2.in", "r" );
  FILE *fout = fopen( "euclid2.out", "w" );

  int t;
  for( fscanf( fin, "%d", &t ); t--; ){
    int a, b;
    fscanf( fin, "%d%d", &a, &b );

    while( b ){
      int r = a % b;
      a = b;
      b = r;
    }

    fprintf( fout, "%d\n", a );
  }

  fclose( fin );
  fclose( fout );
  return 0;
}
