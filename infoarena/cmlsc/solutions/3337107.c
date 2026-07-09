#include <stdio.h>

short A[1024], B[1024], w[1024], mat[1025][1025];

int main() {
  FILE *fin, *fout;
  int n, m, i, j, x;

  fin = fopen( "cmlsc.in", "r" );
  fscanf( fin, "%d%d", &n, &m );
  for ( i = 1; i <= n; i++ )
    fscanf( fin, "%hd", &A[i] );
  for ( i = 1; i <= m; i++ )
    fscanf( fin, "%hd", &B[i] );
  fclose( fin );

  for ( i = 1; i <= n; i++ )
    for ( j = 1; j <= m; j++ )
      if ( A[i] == B[j] )
        mat[i][j] = mat[i - 1][j - 1] + 1;
      else
        mat[i][j] = mat[i - 1][j] < mat[i][j - 1] ? mat[i][j - 1] : mat[i - 1][j];

  x = mat[i = n][j = m];
  while ( x > 0 )
    if ( mat[i - 1][j] == x ) {
      i--;
    } else if ( mat[i][j - 1] == x ) {
      j--;
    } else { /// mat[i - 1][j - 1] == x
      w[--x] = A[i--];
      j--;
    }

  fout = fopen( "cmlsc.out", "w" );
  fprintf( fout, "%hd\n", mat[n][m] );
  for ( i = 0; i < mat[n][m]; i++ )
    fprintf( fout, "%hd ", w[i] );
  fclose( fout );

  return 0;
}
