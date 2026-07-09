#include <stdio.h>

#define maxim(a, b) ((a > b) ? a : b)
int R[1025][1025], sir[1025];

int main() {
    int N, M, i, j, k = 0;
    unsigned char a[1025], b[1025];
    FILE* input = fopen("cmlsc.in", "r");
    FILE* output = fopen("cmlsc.out", "w");
    fscanf(input, "%d %d", &M, &N);
    for (i = 1; i <= M; i++) {
        fscanf(input, "%d", &a[i]);
    }
    for (i = 1; i <= N; i++) {
        fscanf(input, "%d", &b[i]);
    }

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            if (a[i] == b[j]) {
                R[i][j] = 1 + R[i-1][j-1];
            } else {
                R[i][j] = maxim(R[i-1][j], R[i][j-1]);
            }
        }
    }

    for (i = M, j = N; i > 0 && j > 0; ) {
        if (a[i] == b[j]) {
            sir[++k] = a[i];
            i--, j--;
        } else if (R[i-1][j] < R[i][j-1]) {
            j--;
        } else {
            i--;
        }
    }

    fprintf(output, "%d\n", k);
    for (i = k; i; i--) {
        fprintf(output, "%d ", sir[i]);
    }

    return 0;
}