#include <stdio.h>
#include <stdlib.h>
#define NMAX 1024

int l[NMAX+1][NMAX+1];
int v1[NMAX], v2[NMAX], rez[NMAX];

int main() {
    FILE *fin, *fout;
    int n, m, i, j, max;
    fin = fopen( "cmlsc.in", "r" );
    fscanf( fin, "%d%d", &n, &m );
    for( i = 0; i < n; i++ )
      fscanf( fin, "%d", &v1[i] );
    for( i = 0; i < m; i++ )
      fscanf( fin, "%d", &v2[i] );
    fclose( fin );
    for( i = 0; i < n; i++ ) {
      for( j = 0; j < m; j++ ) {
        if( v1[i] == v2[j] )
          l[i+1][j+1] = l[i][j] + 1;
        else
          l[i+1][j+1] = l[i][j+1] > l[i+1][j] ? l[i][j+1] : l[i+1][j];
      }
    }
    fout = fopen( "cmlsc.out", "w" );
    fprintf( fout, "%d\n", l[n][m] );
    i = n;
    j = m;
    max = l[n][m];
    while( max > 0 ) {
      if( l[i-1][j] == max )
        i--;
      else if( l[i][j-1] == max )
        j--;
      else {
        max--;
        i--;
        j--;
        rez[max] = v1[i];
      }
    }
    for( i = 0; i < l[n][m]; i++ )
      fprintf( fout, "%d ", rez[i] );
    fclose( fout );
    return 0;
}
