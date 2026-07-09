#include <stdio.h>
#include <stdlib.h>

int v1[1025], v2[1025], com[1024];
int cmlsc[1025][1025];

struct directie {
    int lin[1025][1025];
    int col[1025][1025];
} dir;

int max( int a, int b ) {
    return a > b ? a : b;
}

int main() {
    FILE *fin, *fout;
    int n, m, i, j, k, x, y, ok;
    fin = fopen( "cmlsc.in", "r" );
    fout = fopen( "cmlsc.out", "w" );
    fscanf( fin, "%d%d", &n, &m );
    for ( i = 1; i <= n; i++ )
        fscanf( fin, "%d", &v1[i] );
    for ( i = 1; i <= m; i++ )
        fscanf( fin, "%d", &v2[i] );
    for ( i = 1; i <= n; i++ ) {
        for ( j = 1; j <= m; j++ ) {
            //cmlsc[i][j] = max( cmlsc[i-1][j-1] + ( v1[i] == v2[j] ), max( cmlsc[i][j-1], cmlsc[i-1][j] ) );
            if ( cmlsc[i-1][j-1] + ( v1[i] == v2[j] ) > max( cmlsc[i][j-1], cmlsc[i-1][j] ) ) {
                cmlsc[i][j] = cmlsc[i-1][j-1] + ( v1[i] == v2[j] );
                dir.lin[i][j] = i - 1;
                dir.col[i][j] = j - 1;
            } else {
                cmlsc[i][j] = max( cmlsc[i][j-1], cmlsc[i-1][j] );
                if ( cmlsc[i][j-1] > cmlsc[i-1][j] ) {
                    dir.lin[i][j] = i;
                    dir.col[i][j] = j - 1;
                } else {
                    dir.lin[i][j] = i - 1;
                    dir.col[i][j] = j;
                }
            }
        }
    }
    fprintf( fout, "%d\n", cmlsc[n][m] );
    i = n;
    j = m;
    k = 0;
    while ( i != 0 && j != 0 ) {
        if ( dir.lin[i][j] == i - 1 && dir.col[i][j] == j - 1 ) {
            com[k] = v1[i];
            k++;
        }
        i = dir.lin[i][j];
        j = dir.col[i][j];
    }
    for ( i = k - 1; i >= 0; i-- )
        fprintf( fout, "%d ", com[i] );
    fclose( fin );
    fclose( fout );
    return 0;
}
