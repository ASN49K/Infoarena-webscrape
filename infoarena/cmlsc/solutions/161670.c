#include <stdio.h>

#define NX 1024

#define MAX(a,b) ( (a) > (b) ? (a) : (b) )

int M, N, a[ NX ], b[ NX ], sol[ NX ];
int c[ NX ][ NX ];

void cit() {
     int i;
     
     scanf( "%d%d", &N, &M );
     
     for( i = 1; i <= N; i++ )
          scanf( "%d", &a[i] );
     for( i = 1; i <= M; i++ )
          scanf( "%d", &b[i] );
}

void rez() {
     int i, j;
     
     for( i = 1; i <= N; i++ )
          for( j = 1; j <= M; j++ )
               if( a[i] == b[j] )
                   c[i][j] = 1 + c[i-1][j-1];
               else
                   c[i][j] = MAX( c[i-1][j], c[i][j-1] );
}

void scr() {
     int i, j;
     
     printf( "%d\n", c[N][M] );
     
     i = N, j = M;
     while( i && j ) {
            if( a[i] == b[j] ) sol[ ++sol[0] ] = a[i], i--, j--; else
            if( c[i-1][j] > c[i][j-1] ) i--; else
            j--;
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
