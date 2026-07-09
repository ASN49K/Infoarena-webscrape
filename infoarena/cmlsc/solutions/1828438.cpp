#include <stdio.h>

#define MAX_SIZE 1024

using namespace std;

FILE *fin = fopen("cmlsc.in", "r");
FILE *fout = fopen("cmlsc.out", "w");

int N, M;
int a[MAX_SIZE + 1];
int b[MAX_SIZE + 1];
int sol[MAX_SIZE + 1];
int max_len;

int ma[MAX_SIZE + 1][MAX_SIZE + 1];

int MAX(int a, int b) {
    return a > b ? a : b;
}

int main(){
    int i, j;

    fscanf(fin, "%d %d", &N, &M);
    for (i = 1; i <= N; i++)
        fscanf(fin, "%d", &a[i]);
    for (i = 1; i <= M; i++)
        fscanf(fin, "%d", &b[i]);

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            if (a[i] == b[j]) {
                ma[i][j] = ma[i - 1][j - 1] + 1;
            }
            else {
                ma[i][j] = MAX(ma[i - 1][j], ma[i][j - 1]);
            }
        }
    }

    max_len = ma[N][M];

    i = N;
    j = M;
    while (i && j) {
        if (a[i] == b[j]) {
            sol[ma[i][j]] = a[i];
            i--;
            j--;
        }
        else {
            if (ma[i - 1][j] > ma[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }

    fprintf(fout, "%d\n", max_len);
    for (i = 1; i <= max_len; i++)
        fprintf(fout, "%d ", sol[i]);
    fprintf(fout, "\n");

    fclose(fin);
    fclose(fout);
    return 0;
}
