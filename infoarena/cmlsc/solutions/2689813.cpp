#include <bits/stdc++.h>

using namespace std;

ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );

const int NMAX = 1024;
int mat[NMAX + 2][NMAX + 2];
int rez[NMAX + 2];
int a[NMAX + 1];
int b[NMAX + 1];

int main() {
  int n, m, i, j, sol;
  fin >> n >> m;
  for( i = 1; i <= n; ++i )
    fin >> a[i];
  for( i = 1; i <= m; ++i )
    fin >> b[i];
  for( i = 1; i <= n; ++i )
    for( j = 1; j <= m; ++j )
      if( a[i] == b[j] )
        mat[i][j] = mat[i - 1][j - 1] + 1;
      else
        mat[i][j] = max(mat[i][j - 1], mat[i - 1][j]);
  fout << mat[n][m] << "\n";
  i = n; j = m; sol = mat[n][m];
  while( sol > 0 ){
    if( mat[i][j - 1] == sol )
      --j;
    else if( mat[i - 1][j] == sol )
      --i;
    else{
      rez[sol] = a[i];
      --i; --j;
      --sol;
    }
  }
  for( i = 1; i <= mat[n][m]; ++i )
    fout << rez[i] << " ";
  return 0;
}
