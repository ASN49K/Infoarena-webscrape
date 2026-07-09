#include <cstdio>
#include <algorithm>

using namespace std;

#define FILEIN "cmlsc.in"
#define FILEOUT "cmlsc.out"
#define NMAX 1026

int A[NMAX], B[NMAX], C[NMAX], D[NMAX][NMAX];

int N, M;

int main() {
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);

    scanf("%d %d", &N, &M);

    for ( int i = 1; i <= N; i++ ) {
        scanf("%d", &A[i]);
    }

    for ( int i = 1; i <= M; i++ ) {
        scanf("%d", &B[i]);
    }

    for ( int i = 1; i <= N; i++ ) {
        for ( int j = 1; j <= M; j++ ) {
            if (A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else {
                D[i][j] = max(D[i][j-1], D[i-1][j]);
            }
        }
    }

    int i = N, j = M, k = 0;
    while ( i && j ) {
        if (A[i] == B[j]) {
            C[++k] = A[i];
            i--; j--;
        } else {
            if (D[i][j-1] > D[i-1][j])
                j--;
            else
                i--;
        }
    }

    printf("%d\n", k);
    for ( ; k; k-- ) {
        printf("%d ", C[k]);
    }
    printf("\n");

    return 0;
}
