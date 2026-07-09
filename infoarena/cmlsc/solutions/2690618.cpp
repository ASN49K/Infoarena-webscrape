#include <stdio.h>
#define NMAXX 1024
int v[NMAXX], mat[NMAXX + 1][NMAXX + 1], sirm[NMAXX + 1], directii[NMAXX + 1][NMAXX + 1];
int main()
{
    FILE *fin, *fout;
    int m, n, i, j, a, maxx, l, c;
    fin = fopen( "cmlsc.in", "r" );
    fout = fopen( "cmlsc.out", "w" );
    fscanf( fin, "%d%d", &m, &n );
    for ( i = 1; i <= m; i++ ) {
        fscanf( fin, "%d", &sirm[i] );
    }
    maxx = 0;
    for ( i = 1; i <= n; i++ ) {
        fscanf( fin, "%d", &a );
        for ( j = 1; j <= m; j++ ) {
            if ( a == sirm[j] ) {
                mat[i][j] = mat[i - 1][j - 1] + 1;
                if ( mat[i][j] > maxx ) {
                    maxx = mat[i][j];
                    l = i;
                    c = j;
                }
                directii[i][j] = 1;
            } else {
                if ( mat[i - 1][j] > mat[i][j - 1] ) {
                    mat[i][j] = mat[i - 1][j];
                    directii[i][j] = 2;
                } else {
                    mat[i][j] = mat[i][j - 1];
                    directii[i][j] = 3;
                }
            }
        }
    }
    i = 1;
    while ( mat[l][c] > 0 ) {
        if ( directii[l][c] == 1 ) {
            v[maxx - i] = sirm[c];
            l--;
            c--;
            i++;
        } else if ( directii[l][c] == 2 ) {
            l--;
        } else {
            c--;
        }
    }
    fprintf( fout, "%d\n", maxx );
    for ( i = 0; i < maxx; i++ ) {
        fprintf( fout, "%d ", v[i] );
    }
    fclose( fin );
    fclose( fout );
    return 0;
}
