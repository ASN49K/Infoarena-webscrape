#include "stdio.h"

int main()
{
    const int VEC_LEN = 1024;
    
    int M, N;
    int A[VEC_LEN + 1], B[VEC_LEN + 1], C[VEC_LEN + 1];
    
    int P[VEC_LEN + 1][VEC_LEN + 1];
    int Q[VEC_LEN + 1][VEC_LEN + 1];
    
    int MAX;
    
    int i, j, k;
    
    FILE *fileIn = fopen("cmlsc.in", "r");
    FILE *fileOut = fopen("cmlsc.out", "w");
    
    fscanf(fileIn, "%d", &M);
    fscanf(fileIn, "%d", &N);
    
    for(i = 1; i <= M; i++) {
        fscanf(fileIn, "%d", A + i);
    }
    for(i = 1; i <= N; i++) {
        fscanf(fileIn, "%d", B + i);
    }
    
    for(i = 0; i < M; i++) {
        P[0][i] = 0;
        Q[0][i] = 0;
    }
    for(i = 0; i < N; i++) {
        P[i][0] = 0;
        Q[i][0] = 0;
    }
    
    for(i = 1; i <= M; i++) {
        for(j = 1; j <= N; j++) {
            if(A[i] == B[j]) {
                P[i][j] = P[i - 1][j - 1] + 1;
                Q[i][j] = 1;
            } else {
                int sus = P[i - 1][j];
                int stanga = P[i][j - 1];
                if(sus > stanga) {
                    P[i][j] = sus;
                    Q[i][j] = 2;
                } else if(sus < stanga) {
                    P[i][j] = stanga;
                    Q[i][j] = 3;
                } else {
                    P[i][j] = stanga;
                    Q[i][j] = 4;
                }
            }
        }
    }
    
    MAX = P[M][N];
    i = M;
    j = N;
    for(k = MAX; k > 0; k--) {
        switch(Q[i][j]) {
            case 1:
                C[k] = A[i];
                i -= 1;
                j -= 1;
            break;
            
            case 2:
                i -= 1;
            break;
            
            case 3:
                j -= 1;
            break;
            
            case 4:
                i -= 1;
            break;
        }
    }
    
    fprintf(fileOut, "%d\n", MAX);
    for(i = 1; i <= MAX; i++) {
        fprintf(fileOut, "%d ", C[i]);
    }
    
    fclose(fileIn);
    fclose(fileOut);
    
    return 0;
}