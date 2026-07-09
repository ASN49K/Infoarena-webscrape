
#include <stdio.h>
#include <stdlib.h>

#define NMAX 1024

int veca[NMAX + 1], vecb[NMAX + 1];
int mat[NMAX + 1][NMAX + 1];
int rasp[NMAX + 1];

int main()
{
    FILE *fin, *fout;
    int num_n, num_m, ind, ind1, secvmax;

    fin = fopen( "cmlsc.in", "r" );
    fscanf( fin, "%d%d", &num_n, &num_m );

    for ( ind = 1; ind <= num_n; ind++ )
      fscanf( fin, "%d", &veca[ind] );

    for ( ind = 1; ind <= num_m; ind++ )
      fscanf( fin, "%d", &vecb[ind] );
    fclose( fin );

    for ( ind = 1; ind <= num_n; ind++ ) {
      for ( ind1 = 1; ind1 <= num_m; ind1++ ) {
        if ( veca[ind] == vecb[ind1] )
          mat[ind][ind1] = mat[ind - 1][ind1 - 1] + 1;
        else {
          if ( mat[ind][ind1 - 1] > mat[ind - 1][ind1] )
            mat[ind][ind1] = mat[ind][ind1 - 1];
          else
            mat[ind][ind1] = mat[ind - 1][ind1];
        }
      }
    }
    secvmax = mat[num_n][num_m];

    fout = fopen( "cmlsc.out", "w" );
    fprintf( fout, "%d\n", secvmax );

    ind = secvmax;
    while ( ind > 0 ) {
      if ( mat[num_n - 1][num_m] == ind )
        num_n--;
      else if ( mat[num_n][num_m - 1] == ind )
        num_m--;
      else {
        rasp[ind--] = veca[num_n];
        num_n--;
        num_m--;
      }
    }

    for ( ind = 1; ind <= secvmax; ind++ )
      fprintf( fout, "%d ", rasp[ind] );
    fclose( fout );
    return 0;
}
