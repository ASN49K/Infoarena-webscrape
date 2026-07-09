#include <stdio.h>

int main() {
    FILE *fin, *fout;
    int t, r;

    fin = fopen( "euclid2.in", "r" );
    fscanf( fin, "%d", &t );
    fout = fopen( "euclid2.out", "w" );

    for ( int i = 1; i <= t; ++i ) {
      int a, b;
      fscanf( fin, "%d%d", &a, &b );
      while ( b > 0 ) {
        r = b;
        b = a % b;
        a = r;
      }
      fprintf( fout, "%d\n", a );
    }
    fclose( fin );
    fclose( fout );
    return 0;
}
