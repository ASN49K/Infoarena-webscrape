#include <stdio.h>
#define max( a, b) ( ( a>b ) ? a:b )
unsigned char a[1025], b[1025], sir[1025];
short int matrix[1025][1025];
int main()
{
    int n, m, nr, i, j, poz;
    FILE *fin, *fout;
    fin = fopen( "cmlsc.in", "r" );
    fscanf( fin, "%d%d", &m, &n );
    for( i=1; i<=m; i++ ){
        fscanf( fin, "%d", &nr );
        a[i] = nr;
    }
    for( i=1; i<=n; i++ ){
        fscanf( fin, "%d", &nr );
        b[i] = nr;
    }
    fclose( fin );
    for( i=1; i<=m; i++ ){
        for( j=1; j<=n; j++ ){
            if( a[i]==b[j] )
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = max( matrix[i-1][j], matrix[i][j-1] );
        }
    }
    poz = -1;
    i = m;
    j = n;
    while( i!=0 && j!=0 ){
        if( a[i]==b[j] ){
            poz++;
            sir[poz] = a[i];
            i--;
            j--;
        }
        else{
            if( matrix[i-1][j]==matrix[i][j] )
                i--;
            else
                j--;
        }
    }
    fout = fopen( "cmlsc.out", "w" );
    fprintf( fout, "%hd\n", matrix[m][n] );
    for( i=poz; i>=0; i-- )
        fprintf( fout, "%d ", sir[i] );
    fputc( '\n', fout );
    fclose( fout );

    return 0;
}
