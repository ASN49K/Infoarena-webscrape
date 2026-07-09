#include <stdio.h>

#define NMax 1024
#define maxim(a, b) ((a > b) ? a : b)

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main() {
    int i, j;
    
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);
    for (i = 1; i <= M; i++)
        scanf("%d", &A[i]);

    for (i = 1; i <= N; i++)
        scanf("%d", &B[i]);

    memset(D, 0, sizeof(D));

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            if (A[i] == B[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else
                D[i][j] = maxim(D[i - 1][j], D[i][j - 1]);
        }
    }

    bst = 0;
    for (i = M, j = N; i > 0 && j > 0;) {
        if (A[i] == B[j]) {
            sir[bst++] = A[i];
            i--;
            j--;
        }
        else {
            if (D[i][j] == D[i - 1][j])
                i--;
            else
                j--;
        }
    }

    printf("%d\n", bst);
    for (i = bst - 1; i >= 0; i--) {
        printf("%d ", sir[i]);
    }

    return 0;
}

