#include <stdio.h>
#define NMAX 1024
int a[NMAX + 1], b[NMAX + 1], sir[NMAX], tab[NMAX + 1][NMAX + 1], dir[NMAX + 1][NMAX + 1];
int dl[3] = { -1, 0, -1 }, dc[3] = { -1, -1, 0 };
int main() {
    FILE *fin, *fout;
    int m, n, d, l, c, i, j;
    fin = fopen( "cmlsc.in", "r" );
    fscanf( fin, "%d%d", &m, &n );
    for ( i = 1; i <= m; i++ )
        fscanf( fin, "%d", &a[i] );
    for ( j = 1; j <= n; j++ )
        fscanf( fin, "%d", &b[j] );
    fclose( fin );
    for ( i = 1; i <= m; i++ ) {
        for ( j = 1; j <= n; j++ ) {
            if ( a[i] == b[j] ) {
                tab[i][j] = tab[i - 1][j - 1] + 1;
                dir[i][j] = 0;
            } else {
                if ( tab[i][j - 1] > tab[i - 1][j]) {
                    tab[i][j] = tab[i][j - 1];
                    dir[i][j] = 1;
                } else {
                    tab[i][j] = tab[i - 1][j];
                    dir[i][j] = 2;
                }
            }
        }
    }
    l = m;
    c = n;
    while ( tab[l][c] >= 1 ) {
        d = dir[l][c];
        if ( d == 0 )
            sir[tab[l][c] - 1] = a[l];
        l += dl[d];
        c += dc[d];
    }
    fout = fopen( "cmlsc.out", "w" );
    fprintf( fout, "%d\n", tab[m][n] );
    for ( i = 0; i < tab[m][n]; i++ )
        fprintf( fout, "%d ", sir[i] );
    fclose( fout );
    return 0;
}
