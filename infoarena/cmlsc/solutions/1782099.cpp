#include <iostream>
#include <cstdio>

#define MAX_LENGTH 1025

using namespace std;

FILE* fin = fopen("cmlsc.in", "r");
FILE* fout = fopen("cmlsc.out", "w");

int c[MAX_LENGTH][MAX_LENGTH], a[MAX_LENGTH], b[MAX_LENGTH];

void PrintSol(int i, int j) {
    while (a[i] != b[j]) {
        if (c[i-1][j] >= c[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    if (c[i-1][j-1] > 0) {
        PrintSol(i-1, j-1);
    }
    fprintf(fout, "%d ", a[i]);
}

int main()
{
    int m, n;
    int i, j, maxLength = -1, maxI, maxJ;

    fscanf(fin, "%d %d", &m, &n);

    for (i = 1; i <= m; ++i) {
        fscanf(fin, "%d", &a[i]);
    }
     for (i = 1; i <= n; ++i) {
        fscanf(fin, "%d", &b[i]);
    }

     for (i = 0; i < m; ++i) {
        c[i][0] = 0;
    }
      for (i = 0; i < n; ++i) {
        c[0][i] = 0;
    }

    for (i = 1; i <= m; ++i){
        for (j = 1; j <= n; ++j) {
            if (a[i] == b[j]) {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
            if (c[i][j] > maxLength) {
                maxLength = c[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    fprintf(fout, "%d\n", maxLength);
    PrintSol(maxI, maxJ);

    fclose(fin);
    fclose(fout);

    return 0;
}
