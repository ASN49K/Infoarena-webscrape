#include <cstdio>
#include <algorithm>
using namespace std;

#define Nmax 1026

FILE *f = fopen ( "cmlsc.in", "r" );
FILE *g = fopen ( "cmlsc.out", "w" );

int D[Nmax][Nmax], A[Nmax], B[Nmax], sir[Nmax];

int main(){

    int N, M;

    fscanf ( f, "%d%d", &N, &M );

    for ( int i = 1; i <= N; ++i )
        fscanf ( f, "%d", &A[i] );
    for ( int i = 1; i <= M; ++i )
        fscanf ( f, "%d", &B[i] );

    for ( int i = 1; i <= N; ++i ){
        for ( int j = 1; j <= M; ++j ){
            if ( A[i] == B[j] )
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = max ( D[i-1][j], D[i][j-1] );
        }
    }

    fprintf ( g, "%d\n", D[N][M] );

    int i = N, j = M, lg = D[N][M];

    while ( i ){
        if ( A[i] == B[j] ){
            sir[lg--] = A[i];
            i--;
            j--;
        }
        else{
            if ( D[i-1][j] > D[i][j-1] )
                i--;
            else
                j--;
        }
    }

    for ( int i = 1; i <= D[N][M]; ++i )
        fprintf ( g, "%d ", sir[i] );

    return 0;
}
