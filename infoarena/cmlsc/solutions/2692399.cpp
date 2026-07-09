// Mihai Priboi

#include <bits/stdc++.h>

#define MAXN 1 << 10

int d[MAXN][MAXN];
unsigned char a[MAXN], b[MAXN], r[MAXN];

int main() {
  FILE *fin, *fout;
  int n, m, i, j, x, nr;
  fin = fopen( "cmlsc.in", "r" );

  fscanf( fin, "%d%d", &n, &m );
  for( i = 0; i < n; i++ ) {
    fscanf( fin, "%d", &x );
    a[i] = x - 1;
  }
  for( i = 0; i < m; i++ ) {
    fscanf( fin, "%d", &x );
    b[i] = x - 1;
  }

  fclose( fin );

  // dinamica
  for( i = 0; i < n; i++ )
    d[i][0] = a[i] == b[0];
  for( i = 0; i < m; i++ )
    d[0][i] = a[0] == b[i];

  for( i = 1; i < n; i++ ) {
    for( j = 1; j < m; j++ ) {
      if( a[i] == b[j] )
        d[i][j] = d[i - 1][j - 1] + 1;
      else
        d[i][j] = std::max( d[i][j - 1], d[i - 1][j] );
    }
  }

  // solutia
  i = n - 1;
  j = m - 1;
  nr = 0;
  while( i > 0 || j > 0 ) {
    if( a[i] == b[j] ) {
      r[nr++] = a[i] + 1;
      i--;
      j--;
    }
    else if( i > 0 && d[i - 1][j] >= d[i][j - 1] )
      i--;
    else
      j--;
  }

  fout = fopen( "cmlsc.out", "w" );

  fprintf( fout, "%d\n", d[n - 1][m - 1] );
  for( i = nr - 1; i >= 0; i-- )
    fprintf( fout, "%d ", r[i] );

  fclose( fout );
  return 0;
}
