#include <cstdio>
#define Nmax 1025

using namespace std;

inline int max(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}

int main() {
    int M, N, i, j, bst = 0, sir[Nmax];
    short A[Nmax], B[Nmax], D[Nmax][Nmax];

    freopen("cmlsc.in",  "r", stdin);
    //freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &M, &N);
    for (i = 1; i <= M; ++i) {
        scanf("%d", &A[i]);
        D[0][i] = 0;
    }
    for (i = 1; i <= N; ++i) {
        scanf("%d", &B[i]);
        D[i][0] = 0;
    }
    D[0][0] = 0;

    for (i = 1; i <= M; ++i)
        for (j = 1; j <= N; ++j)
            if (A[i] == B[j])
                D[i][j] = D[i-1][j-1]+1;
            else
                D[i][j] = max(D[i][j-1], D[i-1][j]);

    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);

    return 0;
}
