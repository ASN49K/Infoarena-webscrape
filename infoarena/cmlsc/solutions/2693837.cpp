#include <stdio.h>
#include <algorithm>

#define NMAX 1024

using namespace std;

short int v[NMAX + 1][NMAX + 1], sira[NMAX + 1], sirb[NMAX + 1], r[NMAX];

int main() {
  FILE *fin, *fout;
  fin = fopen( "cmlsc.in", "r" );
  fout = fopen( "cmlsc.out", "w" );
  int i, j, a, b, lun;
  fscanf( fin, "%d", &a );
  fscanf( fin, "%d", &b );
  for( i = 1; i <= a; i++ ) {
    fscanf( fin, "%d", &sira[i] );
  }
  for( i = 1; i <= b; i++ ) {
    fscanf( fin, "%d", &sirb[i] );
  }
  for ( i = 1; i <= a; i++ ) {
    for ( j = 1; j <= b; j++ ) {
      if ( sira[i] == sirb[j] ) {
        v[i][j] = v[i - 1][j - 1] + 1;
      }
      else {
        v[i][j] = max( v[i - 1][j], v[i][j - 1] );
      }
    }
  }
  i = a;
  j = b;
  lun = v[a][b];
  while (lun > 0) {
    if ( v[i][j - 1] == lun ) {
      j--;
    } else if (v[i - 1][j] == lun ) {
      i--;
    }
    else {
      r[lun] = sira[i];
      i--;
      j--;
      lun--;
    }
  }

  fprintf(fout, "%d\n", v[a][b]);
  for ( i = 1; i <= v[a][b]; i++ )
    fprintf(fout, "%d ", r[i]);
  return 0;
}
