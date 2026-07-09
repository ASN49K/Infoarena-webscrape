#include <stdio.h>

#define in "cmlsc.in"
#define out "cmlsc.out"
#define NMAX 1030
#define maxim(a,b) ( (a) > (b) ? (a) : (b) )

int S[NMAX],ind;
int A[NMAX], B[NMAX];
int DP[NMAX][NMAX];
int n, m;

int main()
{
    freopen( in, "r", stdin );
    freopen ( out, "w", stdout );
    
    scanf( "%d%d", &n, &m );
    int i,j;
    for ( i = 1; i <= n; scanf("%d", &A[i++]) ); 
    for ( i = 1; i <= m; scanf("%d", &B[i++]) );
    
    DP[0][0] = 0;
    for ( i = 1; i <= n; ++i )
    {
        for ( j = 1; j <= m; ++j )
        {
            if ( A[i] == B[j] ) { DP[i][j] = DP[i-1][j-1] + 1; S[++ind] = A[i]; }
            else                DP[i][j] = maxim(DP[i-1][j], DP[i][j-1] );
        }
    }     
    printf( "%d\n", ind );
    for ( i = 1; i <= ind; printf("%d ", S[i++] ) );
    return 0;
}
