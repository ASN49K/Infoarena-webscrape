#include <stdio.h>
#include <stdlib.h>
#define NMAX 1024

int vm[NMAX + 1], vn[NMAX + 1], sir[NMAX + 1], mat[NMAX + 1][NMAX + 1];

int main()
{
    FILE *fin, *fout;
    fin = fopen( "cmlsc.in", "r" );
    fout = fopen( "cmlsc.out", "w" );
    int n, m, i, j, max;
    fscanf( fin, "%d%d", &m, &n );
    for ( i = 1; i <= m; i++ )
      fscanf( fin, "%d", &vm[i] );
    for ( i = 1; i <= n; i++ )
      fscanf( fin, "%d", &vn[i] );
    for ( i = 1; i <= m; i++ )
      for ( j = 1; j <= n; j++ )
        if ( vm[i] != vn[j] )
          mat[i][j] = mat[i][j - 1] > mat[i - 1][j] ? mat[i][j - 1] : mat[i - 1][j];
        else
          mat[i][j] = 1 + mat[i - 1][j - 1];
    i = m;
    j = n;
    max = 0;
    while ( i > 0 ) {
      if( vm[i] == vn[j] ) {
        max++;
        sir[max] = vm[i];
        i--;
        j--;
      }
      else if( mat[i - 1][j] < mat[i][j - 1] )
        j--;
      else
        i--;
    }
    fprintf( fout, "%d\n", max );
    for ( i = max; i > 0; i-- )
      fprintf( fout, "%d ", sir[i] );
    return 0;
    fclose(fin);
    fclose(fout);
}
