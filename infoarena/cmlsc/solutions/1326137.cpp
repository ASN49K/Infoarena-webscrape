#include<cstdio>
#include<vector>

using namespace std;

FILE *fin = fopen( "cmlsc.in", "r" ), *fout = fopen( "cmlsc.out", "w" );

const int nmax = 1024;
short int a[ nmax + 1 ], b[ nmax + 1 ];
short int d[ nmax + 1 ][ nmax + 1 ];

vector <short int> ans;

inline short int max2( short int x, short int y ) {
    if ( x < y ) {
        return y;
    }
    return x;
}
int main() {
    int n, m;
    fscanf( fin, "%d%d", &n, &m );
    for( int i = 1; i <= n; ++ i ) {
        fscanf( fin, "%hd", &a[ i ] );
    }
    for( int i = 1; i <= m; ++ i ) {
        fscanf( fin, "%hd", &b[ i ] );
    }
    d[ 0 ][ 0 ] = 0;
    for( int i = 1; i <= n; ++ i ) {
        for( int j = 1; j <= m; ++ j ) {
            if ( a[ i ] == b[ j ] ) {
                d[ i ][ j ] = d[ i - 1 ][ j - 1 ] + 1;
            } else {
                d[ i ][ j ] = max2( d[ i - 1 ][ j ], d[ i ][ j - 1 ] );
            }
        }
    }
    fprintf( fout, "%hd\n", d[ n ][ m ] );
    while ( d[ n ][ m ] > 0 ) {
        if ( a[ n ] == b[ m ] ) {
            ans.push_back( a[ n ] );
            -- n; -- m;
        } else {
            if ( d[ n ][ m ] == d[n - 1][ m ] ) {
                -- n;
            } else {
                -- m;
            }
        }
    }
    while ( ans.size() ) {
        fprintf( fout, "%hd ", ans.back() );
        ans.pop_back();
    }
    fprintf( fout, "\n" );
    fclose( fin );
    fclose( fout );
    return 0;
}
