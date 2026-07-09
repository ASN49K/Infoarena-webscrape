#include <cstdio>
using namespace std;

FILE *f = fopen ( "euclid2.in", "r" );
FILE *g = fopen ( "euclid2.out", "w" );

int cmmdc ( int a, int b ){
    int r = a % b;
    while ( r ){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(){

    int T, x, y;

    fscanf ( f, "%d", &T );

    for ( ; T; --T ){
        fscanf ( f, "%d%d", &x, &y );
        fprintf ( g, "%d\n", cmmdc ( x, y ) );
    }

    return 0;
}
