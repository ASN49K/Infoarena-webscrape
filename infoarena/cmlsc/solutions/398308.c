// Simionescu Andrei, 2/18/2010
// http://infoarena.ro/problema/cmlsc
// Dificultate: EASY
// Categorii: PD

#include <stdio.h>
#define NMAX 1025
#define max( A, B ) ((A > B)?(A):(B))

int m, n, a[NMAX], b[NMAX], lcs[NMAX][NMAX], sol[NMAX];

int main(){
 freopen( "cmlsc.in", "r", stdin );
 freopen( "cmlsc.out", "w", stdout );
 
 int i, j, max = 0, k = 0;
  
 scanf( "%d %d", &m, &n );
 
 // input
 for( i = 1; i <= m; ++i )
    scanf( "%d", &a[i] );

 for( i = 1; i <= n; ++i )
    scanf( "%d", &b[i] );
 
 // PD
 for( i = 1; i <= m; ++i )
    for( j = 1; j <= n; ++j )
        {
         if(a[i] == b[j])
            lcs[i][j] = 1 + lcs[i-1][j-1];
         else
            lcs[i][j] = max( lcs[i][j-1], lcs[i-1][j] );
        }
 
 // backtrace
 for( i = m, j = n; i; )
    if( a[i] == b[j] )
    sol[++k] = a[i],
    --i,
    --j;
    else if( lcs[i-1][j] < lcs[i][j-1] )
        --j;
    else
        --i;
        
 // output
 printf( "%d\n", k );
 for( i = k; i; --i )
    printf( "%d ", sol[i] );
 
 return 0;
}
