#include <stdio.h>
#include <fstream>
using namespace std;

#define in "cmlsc.in"
#define out "cmlsc.out"
#define dim 1025

int N, M;
int A[dim], B[dim], Sol[dim];
int C[dim][dim];

inline int Maxim(int a, int b) {
       if ( a > b ) return a;
       return b;
}

int main()
{
    freopen(in,"r",stdin);
    freopen(out,"w",stdout);
    
    memset(C,0,sizeof(C));
    
    scanf("%d%d", &N, &M);
    for ( int i = 1; i <= N; i++ )
        scanf("%d", &A[i]);
    
    for ( int i = 1; i <= M; i++ )
        scanf("%d", &B[i]);
    
    for ( int i = 1; i <= N; i++ )
        for ( int j = 1; j <= M; j++ )
            if ( A[i] == B[j] ) C[i][j] = C[i-1][j-1] + 1;
            else                C[i][j] = Maxim( C[i-1][j], C[i][j-1] );
    
    int maxim = -1;
    
    for ( int i = 1; i <= N; i++ )
        for ( int j = 1; j <= M; j++ )
            maxim = Maxim( maxim, C[i][j] );
    
    printf("%d\n", maxim);
    
    int i = N, j = M, K = maxim;
    while ( 1 )
    {
          if ( A[i] == B[j] ) Sol[K] = A[i], K--, i--, j--;
          else if ( C[i][j-1] < C[i-1][j] ) i--;
          else j--;
          
          if ( !i || !j || !K ) break;
    }
    
    for ( int i = 1; i <= maxim; i++ )
        printf("%d ", Sol[i]);
}
