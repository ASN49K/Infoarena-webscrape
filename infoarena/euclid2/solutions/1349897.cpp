#include <cstdio>

using namespace std;

#define IN_FILE "euclid2.in"
#define OUT_FILE "euclid2.out"

inline int euclid( int a, int b ) {
    int r;
    while( b ) {
        r = b;
        b = a % b;
        a = r;
    }
    return a;
}
int main( ) {
    FILE *f, *g;
    int Q, a, b;

    f = fopen( IN_FILE, "r" );
    fscanf( f, "%d", &Q );
    g = fopen( OUT_FILE, "w" );
    while( Q-- ) {
        fscanf( f, "%d%d", &a, &b );
        fprintf( g, "%d\n", euclid( a, b ) );
    }
    fclose( f );
    fclose( g );
    return 0;
}
