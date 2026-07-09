#include <stdio.h>
#define nmax 1025
#define max(a,b) ( ( (a) > (b) ) ? (a) : (b) )

FILE *fin, *fout;
int n, m, i, j, a[nmax], b[nmax], sol[nmax], lcs[nmax][nmax] ;

int main(void)
{
   //Fisiere
   fin  = fopen ( "cmlsc.in", "r" );
   fout = fopen ( "cmlsc.out", "w" );

   //Citire variabile
   fscanf( fin, "%d", &n );
   fscanf( fin, "%d", &m );

   //Citire a
   for( i = 0 ; i < n ; i++ )
        fscanf( fin, "%d", &a[i] );

   //Citire b
   for( i = 0 ; i < m ; i++ )
        fscanf( fin, "%d", &b[i] );

   //Cel mai lung subsir comun
   for( i = 1 ; i <= n ; i++ )
        for( j = 1 ; j <= m ; j++ )

            if( a[i-1] == b[j-1] )
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max( lcs[i][j-1], lcs[i-1][j] );

    //Reconstituire
    int sx = n;
    int sy = m;
    int k = lcs[sx][sy];
    int ok = 1;

    while( lcs[sx][sy] != 0 )
    {
        ok = 1;
        for( i = sx ; i >= 1 && ok; i-- )
            for( j = sy ; j >= 1 && ok; j-- )
                if( (lcs[i][j] == k )&& (lcs[i][j] == lcs[i-1][j-1] + 1)  && (lcs[i][j] == lcs[i][j-1] + 1) && (lcs[i][j] == lcs[i-1][j] + 1) )
                {
                    sol[k--] = a[i-1];
                    sx = i-1;
                    sy = j-1;
                    ok = 0;
                }
    }

    //Afisare
    fprintf( fout, "%d\n", lcs[n][m]);

    for(i = 1 ; i <= lcs[n][m] ; i++)
        fprintf( fout, "%d ",sol[i]);

    return 0;
}
