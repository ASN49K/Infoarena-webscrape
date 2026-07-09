#include <cstdio>

using namespace std;

FILE *fin = fopen("cmlsc.in","r");
FILE *fout = fopen("cmlsc.out","w");

int N, M, A[1030], B[1030], mat[1030][1030], sol[1030], i, j;

int main() {
    fscanf(fin, "%d %d", &N, &M);

    for(i = 1;i <= N; ++i) {
        fscanf(fin, "%d", &A[i]);
    }

    for(j = 1; j <= M; ++j) {
        fscanf(fin, "%d", &B[j]);
    }

    for(i = 1; i <= N; ++i) {
        for(j = 1; j <= M; ++j) {
            if(A[i] == B[j]) {
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else {
                mat[i][j] = (mat[i][j - 1] > mat[i - 1][j] ? mat[i][j - 1] : mat[i - 1][j]);
            }
        }
    }

    for(i = N, j = M;i;) {
        if(A[i] == B[j]) {
            sol[++sol[0]] = A[i];
            --i;
            --j;
        }
        else {
            if(mat[i - 1][j] > mat[i][j - 1]) {
                --i;
            }
            else {
                --j;
            }
        }
    }

    fprintf(fout, "%d\n", sol[0]);

    for(i = sol[0]; i > 0; --i) {
        fprintf(fout, "%d ", sol[i]);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
