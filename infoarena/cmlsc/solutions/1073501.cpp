//Subsecventa comuna maximala : http://www.infoarena.ro/problema/cmlsc
#include <cstdio>
#define MAXN 1025

inline int max( int x, int y ){
    return (x > y) ? x : y;
}

int M[MAXN][MAXN], a[MAXN], b[MAXN], sol[MAXN];

int main () {
    FILE *f, *g;
    f = fopen( "cmlsc.in", "r" );
    g = fopen( "cmlsc.out", "w" );

    int m, n, best = 0, i, j;

    fscanf( f, "%d%d", &m, &n );

    //Vectorii sunt de la 1 pentru a calcula mai usor matricea-solutie
    for( i = 1 ; i <= m ; ++i )
        fscanf( f, "%d", &a[i] );
    for( j = 1 ; j <= n ; ++j )
        fscanf( f, "%d", &b[j] );

    //construire matrice M

    for( i = 1 ; i <= m ; ++i )
        for( j = 1 ; j <= n ; ++j ) {
            if( a[i] == b[j] )
                M[i][j] = M[i - 1][j - 1] + 1;
            else M[i][j] = max( M[i - 1][j], M[i][j-1] );
        }

    //construire subsecventa comuna maximala

    i = m, j = n;
    best = 0;
    while( i ) {
        if( a[i] == b[j] ) {
            sol[++best] = a[i];
            --i;
            --j;
        }
        else if( M[i-1][j] < M[i][j-1] )
            --j;
        else
            --i;
    }

    fprintf( g, "%d\n", best );

    for( i = best ; i >= 1 ; --i )
        fprintf( g, "%d ", sol[i] );

    fclose( f );
    fclose( g );

    return 0;
}




