#include <stdio.h>
#include <stdlib.h>

const int MAXN = 1024;

inline int max(int a, int b) {
    if(a < b) return b;
    else return a;
}

int main()
{
    int i, j, m, n, best;
    int* vecA = (int*)malloc(MAXN*sizeof(int));
    int* vecB = (int*)malloc(MAXN*sizeof(int));
    int* rez = (int*)malloc(MAXN*sizeof(int));

    FILE *in;   in  = fopen("cmlsc.in", "r");
    FILE *out;  out = fopen("cmlsc.out", "w");

    fscanf( in, "%d%d", &m, &n );

    int** din = (int**)malloc((m + 2)*sizeof(int *));
    for(i = 0; i <= m; i++)
        din[i] = (int *) malloc((n + 2)*sizeof(int));

    for(i = 1; i <= m; i++) {
        fscanf( in, "%d", &vecA[i] );
        din[i][0] = 0;
    }
    for(i = 1; i <= n; i++) {
        fscanf( in, "%d", &vecB[i] );
        din[0][i] = 0;
    }
    fclose( in );

    din[0][0] = 0;
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if(vecA[i] == vecB[j]) {
                din[i][j] = 1 + din[i-1][j-1];
            } else {
                din[i][j] = max(din[i-1][j], din[i][j-1]);
            }
        }
    }

    best = 0;
    i = m; j = n;
    while(i > 0) {
        if(vecA[i] == vecB[j]) {
            rez[++best] = vecA[i];
            i--; j--;
        } else if(din[i][j-1] > din[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }

    fprintf( out, "%d\n", best );
    for(i = best; i > 0; --i) {
        fprintf( out, "%d ", rez[i] );
    }
    fclose( out );

    return 0;
}
