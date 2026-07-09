# include <stdio.h>
# include <stdlib.h>

# define MAX_N 1024
# define MAX_M 1024

# define undefined -1

unsigned char a[MAX_N + 1];
unsigned char b[MAX_M + 1];

int s[MAX_N + 1][MAX_M + 1];

int max( int a, int b ) {
    return a > b ? a : b;
}

int cmlsc( int n, int m ) {
    if ( s[n][m] == undefined ) {
        if ( a[n] == b[m] )
            s[n][m] = 1 + cmlsc( n - 1, m - 1 );
        else
            s[n][m] = max( cmlsc( n - 1, m ), cmlsc( n, m - 1 ) );
    }

    return s[n][m];
}

void back( int n, int m, FILE *fout ) {
    if ( !n || !m )
        return;

    if ( a[n] == b[m] ) {
        back( n - 1, m - 1, fout );
        fprintf( fout, "%d ", a[n] );
    } else {
        if ( cmlsc( n - 1, m ) > cmlsc( n, m - 1 ) )
            back( n - 1, m, fout );
        else
            back( n, m - 1, fout );
    }
}

int main() {
    FILE *fin = fopen( "cmlsc.in", "r" ), *fout = fopen( "cmlsc.out", "w" );

    int n, m, i, j;

    fscanf( fin, "%d%d", &n, &m );

    for ( i = 1; i <= n; i ++ )
        fscanf( fin, "%d", &a[i] );

    for ( i = 1; i <= m; i ++ )
        fscanf( fin, "%d", &b[i] );

    for ( i = 1; i <= n; i ++ )
        for ( j = 1; j <= m; j ++ )
            s[i][j] = undefined;

    fprintf( fout, "%d\n", cmlsc( n, m ) );
    back( n, m, fout );

    fclose( fin );
    fclose( fout );

    return 0;
}
