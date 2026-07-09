#include <stdio.h>

int main() {
    FILE *intrare = fopen("cmlsc.in", "r");
    FILE *iesire = fopen("cmlsc.out", "w");

    if (intrare == NULL || iesire == NULL) {
        printf("Eroare la deschiderea fișierelor.\n");
        return 1;
    }

    int M, N;
    fscanf(intrare, "%d" "%d", &M, &N);
    int A[M], B[N];
    for(int i = 0; i < M; i++) {
        fscanf(intrare, "%d", &A[i]);
    }
    for(int j = 0; j < N; j++) {
        fscanf(intrare, "%d", &B[j]);
    }

    int dp[M+1][N+1];
    
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1; 
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1]; 
            }
        }
    }

    int lcsLength = dp[M][N];

    fprintf(iesire, "%d\n", lcsLength);

    int i = M, j = N;
    int lcs[lcsLength]; 

    int index = lcsLength - 1; 
    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            lcs[index] = A[i-1]; 
            index--;
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    for (int k = 0; k < lcsLength; k++) {
        fprintf(iesire, "%d ", lcs[k]);
    }

    fclose(intrare);
    fclose(iesire);

    return 0;
}