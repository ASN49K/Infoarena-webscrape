#include <stdio.h>

int v1[1024], v2[1024], dp[1025][1025], sol[1024];
int max( int a, int b ){
  if ( a < b ){
    a = b;
  }
  return a;
}
int main()
{
  FILE *fin, *fout;
  fin = fopen( "cmlsc.in", "r" );
  fout = fopen( "cmlsc.out", "w" );
  int n, m, i, j, cnt;
  fscanf( fin, "%d%d", &n, &m );
  for ( i = 0; i < n; i++ )
    fscanf( fin, "%d", &v1[i] );
  for ( i = 0; i < m; i++ )
    fscanf( fin, "%d", &v2[i] );
  fclose( fin );
  for ( i = 1; i <= n; i++ ){
    for ( j = 1; j <= m; j++ ){
      if ( v1[i - 1] == v2[j - 1] )
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );
    }
  }
  i = n;
  j = m;
  cnt = 0;
  while ( i >= 1 && j >= 1 ){
    if ( v1[i - 1] == v2[j - 1] ){
      sol[cnt] = v1[i - 1];
      cnt++;
      i--;
      j--;
    }
    else if ( dp[i][j] == dp[i - 1][j] )
      i--;
    else if ( dp[i][j] == dp[i][j - 1] )
      j--;
  }
  fprintf( fout, "%d\n", dp[n][m] );
  for ( i = cnt - 1; i >= 0; i--)
    fprintf( fout, "%d ", sol[i] );
  fclose( fout );
  return 0;
}
