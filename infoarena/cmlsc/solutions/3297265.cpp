#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

int main() {
  FILE *fin = fopen( "cmlsc.in", "r" );
  FILE *fout = fopen( "cmlsc.out", "w" );

  int n, m;
  fscanf( fin, "%d%d", &n, &m );
  std::vector<int> a(n);
  for( int i = 0; i < n; i++ )
    fscanf( fin, "%d", &a[i] );
  std::vector<int> b(m);
  for( int i = 0; i < m; i++ )
    fscanf( fin, "%d", &b[i] );

  std::vector<std::vector<int>> mata(n+1, std::vector<int>(m+1, 0));
  for( int i = 0; i < n; i++ ){
    for( int j = 0; j < m; j++ ){
      mata[i + 1][j + 1] = std::max( mata[i + 1][j + 1], mata[i + 1][j] );
      mata[i + 1][j + 1] = std::max( mata[i + 1][j + 1], mata[i][j + 1] );
      mata[i + 1][j + 1] = std::max( mata[i + 1][j + 1], (a[i] == b[j]) + mata[i][j] );
    }
  }

  std::vector<int> ret; {
    int i = n, j = m;
    while( i || j ){
      if( i > 0 && mata[i][j] == mata[i - 1][j] ){
        i--;
      }else if( j > 0 && mata[i][j] == mata[i][j - 1] ){
        j--;
      }else{
        i--; j--;
        ret.push_back( a[i] );
      }
    }

    assert( i == 0 && j == 0 );
  }

  std::reverse( ret.begin(), ret.end() );
  fprintf( fout, "%d\n", (int)ret.size() );
  for( int x : ret ) fprintf( fout, "%d ", x );
  fputc( '\n', fout );
  
  fclose( fin );
  fclose( fout );
  return 0;
}
