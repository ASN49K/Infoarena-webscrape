#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 1025;

ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );

pair <int,int> mat[MAXN][MAXN];
int a[MAXN], b[MAXN], sol[MAXN];
int main() {
  int n, m, i, j, nr, l, c, p;
  fin >> n >> m;
  for( i = 1; i <= n; i++ )
    fin >> a[i];
  for( i = 1; i <= m; i++ )
    fin >> b[i];
  for( i = 1; i <= n; i++ ) {
    for( j = 1; j <= m; j++ ) {
      if( a[i] == b[j] ) {
        mat[i][j].first = mat[i-1][j-1].first + 1;
        mat[i][j].second = 2;
      }
      else {
        mat[i][j].first = max( mat[i-1][j].first, mat[i][j-1].first );
        if( mat[i-1][j].first > mat[i][j-1].first )
          mat[i][j].second = 0;
        else
          mat[i][j].second = 1;
      }
    }
  }
  /* for( i = 0; i <= n; i++ ) {
    for( j = 0; j <= m; j++ )
      cout << mat[i][j].first << " ";
    cout << '\n';
  } */
  nr = mat[n][m].first;
  p = 0;
  l = n;
  c = m;
  while( nr > 0 ) {
    if( mat[l][c].second == 0 )
      l--;
    else if( mat[l][c].second == 1 )
      c--;
    else {
      l--;
      c--;
      sol[p++] = a[l+1];
      nr--;
    }
  }
  fout << p << '\n';
  p--;
  while( p >= 0 ) {
    fout << sol[p] << " ";
    p--;
  }
  return 0;
}
