#include <stdio.h>

int main() {
    int t, n, i, j;

    FILE *fin = fopen ( "nim.in", "r" );
    fscanf ( fin, "%d", &t );
    FILE *fout = fopen ( "nim.out", "w" );
    for ( j = 0; j < t; ++j ) {
        fscanf ( fin, "%d", &n );
        int x;
        int sumxor = 0;
        for ( i = 0; i < n; ++i ) {
            fscanf ( fin, "%d", &x );
            sumxor ^= x;
        }
        if ( !sumxor )
            fprintf ( fout, "NU\n" );
        else
            fprintf ( fout, "DA\n" );
    }

    fclose ( fin );
    fclose ( fout );

    return 0;
}
