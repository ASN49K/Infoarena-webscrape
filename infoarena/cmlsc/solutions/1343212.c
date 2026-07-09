#include <stdio.h>
#include <stdlib.h>

const int MAXN = 1024;

int main()
{
    int m, n, best, vecA[MAXN], vecB[MAXN], rez[MAXN], din[MAXN][MAXN];

    FILE *in;   in  = fopen("cmlsc.in", "r");
    FILE *out;  out = fopen("cmlsc.out", "w");

    fscanf( in, "%d%d", &m, &n );
    fclose( in );

    best = 0;
    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            if(vecA[i] == vecB[j]) {
                ++best;
                --i;
                --j;
                rez[best] = vecA[i];
            } else {
                if(din[i][j-1] > din[i-1][j]) {
                    j--;
                } else {
                    i--;
                }
            }
        }
    }

    fprintf( out, "%d", best );
    for(int i = best; i > 0; --i) {
        fprintf( out, "%d ", rez[i] );
    }
    fclose( out );

    return 0;
}
