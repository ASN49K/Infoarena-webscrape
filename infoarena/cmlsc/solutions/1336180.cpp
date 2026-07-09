#include <cstdio>
#include <algorithm>

using namespace std;

#define IN_FILE "cmlsc.in"
#define OUT_FILE "cmlsc.out"
#define MAX_V 1030

FILE *f;
int N, M;
int a[ MAX_V ], b[ MAX_V ];
int d[ MAX_V ][ MAX_V ];
void read( ) {
    register int i;

    f = fopen( IN_FILE, "r" );
    fscanf( f, "%d%d", &N, &M );
    for( i = 1; i <= N; ++i )
        fscanf( f, "%d", a + i );
    for( i = 1; i <= M; ++i )
        fscanf( f, "%d", b + i );
    fclose( f );
}
void dinamic( ) {
    register int i, j;

    for( i = 1; i <= N; ++i ) {
        for( j = 1; j <= M; ++j ) {
            if( a[ i ] == b[ j ] )
                d[ i ][ j ] = 1 + d[ i - 1 ][ j - 1 ];
            else
                d[ i ][ j ] = max( d[ i - 1 ][ j ], d[ i ][ j - 1 ] );
        }
    }
}
void print( ) {
    int sol[ MAX_V ];
    register int i, j;

    *sol = 0;
    i = N;
    j = M;
    while( i && j ) {
        if( a[ i ] == b[ j ] ) {
            sol[ ++*sol ] = a[ i ];
            --i;
            --j;
        } else if( d[ i - 1 ][ j ] > d[ i ][ j - 1 ] )
            --i;
        else
            --j;
    }
    f = fopen( OUT_FILE, "w" );
    fprintf( f, "%d\n%d", d[ N ][ M ], sol[ *sol ] );
    for( i = *sol - 1; i; --i )
        fprintf( f, " %d", sol[ i ] );
    fputc( '\n', f );
    fclose( f );
}
int main( ) {
    read( );
    dinamic( );
    print( );
    return 0;
}
