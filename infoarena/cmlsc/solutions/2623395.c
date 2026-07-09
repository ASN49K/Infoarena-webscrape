#include <stdio.h>
#include <stdlib.h>
#define LIM 1024

char M[LIM + 1][LIM + 1];
int x[LIM + 1], y[LIM + 1];
int dp[LIM + 1][LIM + 1];
int sol[LIM];

int DX[3] = { -1, 0, -1 };
int DY[3] = { -1, -1, 0 };

int main() {
  FILE *fin = fopen( "cmlsc.in", "r" );
  FILE *fout = fopen( "cmlsc.out", "w" );
  int n, m, i, j, max, maxc, dir;

  fscanf( fin, "%d%d", &n, &m );
  for ( i = 1; i <= n; ++i ) {
    fscanf( fin, "%d", &x[i] );
  }
  for ( i = 1; i <= m; ++i ) {
    fscanf( fin, "%d", &y[i] );
  }
  max = 0;
  for ( i = 1; i <= n; ++i ) {
    for ( j = 1; j <= m; ++j ) {
      if ( x[i] == y[j] ) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        M[i][j] = 0;
	  } else {
        if ( dp[i][j - 1] > dp[i - 1][j] ) {
          dp[i][j] = dp[i][j - 1];
          M[i][j] = 1;
        } else {
          dp[i][j] = dp[i - 1][j];
          M[i][j] = 2;
        }
      }
      if ( max < dp[i][j] ) {
        max = dp[i][j];
      }
    }
  }
  fprintf( fout, "%d\n", max );
  maxc = max;
  i = n;
  j = m;
  while ( max > 0 ) {
    if ( M[i][j] == 0 ) {
      sol[--max] = x[i];
    }
    dir = M[i][j];
    i += DX[dir];
    j += DY[dir];
  }
  for ( i = 0; i < maxc; ++i ) {
    fprintf( fout, "%d ", sol[i] );
  }
  fclose( fin );
  fclose( fout );
  return 0;
}

