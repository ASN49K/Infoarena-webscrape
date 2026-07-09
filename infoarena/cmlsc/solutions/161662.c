#include <stdio.h>

#define NX 1024

int M, N, a[ NX ], b[ NX ], sol[ NX ];
int c[ NX ][ NX ], d[ NX ][ NX ];

void cit() {
     int i;
     
     scanf( "%d%d", &N, &M );
     
     for( i = 1; i <= N; i++ )
          scanf( "%d", &a[i] );
     for( i = 1; i <= M; i++ )
          scanf( "%d", &b[i] );
}

void rez() {
     int i, j, max, pmax;
     
     for( i = 1; i <= N; i++ )
          for( j = 1; j <= M; j++ ) {
               max = c[i-1][j], pmax = 1;
               if( max < c[i][j-1] )
                   max = c[i][j-1], pmax = 2;
               if( max < c[i-1][j-1] + 1 && a[i] == b[j] )
                   max = c[i-1][j-1] + 1, pmax = 3;
               c[i][j] = max, d[i][j] = pmax;
          }
}

void scr() {
     int i, j;
     
     printf( "%d\n", c[N][M] );
     
     i = N, j = M;
     while( i && j ) {
            if( d[i][j] == 1 ) i--; else
            if( d[i][j] == 2 ) j--; else
            sol[ ++sol[0] ] = a[i], i--, j--;
     }
     
     for( i = sol[0]; i; i-- )
          printf( "%d ", sol[i] );
}

int main() {
    freopen( "cmlsc.in", "r", stdin );
    freopen( "cmlsc.out", "w", stdout );
    
    cit();
    rez();
    scr();
    
    return 0;
}
