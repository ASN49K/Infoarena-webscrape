#include <stdio.h>
#include <algorithm>

using namespace std;

void buildM(int ** M, int m, int n, int * a, int * b) {
    for (int i = 0; i <= m; i++) {
        M[i][0] = 0;
    }
    for (int i = 0; i <= n; i++) {
        M[0][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                M[i][j] = 1 + M[i - 1][j - 1];
            } else {
                M[i][j] = max(M[i - 1][j], M[i][j - 1]);   
            }
        }
    }
}

void buildAns(int ** M, int m, int n, int * a, int * b, int * ans) {
    int row = m;
    int col = n;
    int idx = 0;

    while (row && col) {
        if (a[row - 1] == b[col - 1]) {
            ans[idx++] = a[row - 1];
            row--; col--;
        } else if (M[row - 1][col] > M[row][col - 1]) {
            row--;
        } else {
            col--;
        }
    }
}

int main() {
    FILE * f;
    int m, n;
    int * a, * b, ** M;

    f = fopen("cmlsc.in", "r");
    fscanf(f, "%d%d", &m, &n);
    // allocating space
    a = new int[m];
    b = new int [n];
    M = new int * [m + 1];
    for (int i = 0; i <= m; i++) {
        M[i] = new int [n + 1];
    }
    //reading the input
    for (int i = 0; i < m; i++) {
        fscanf(f, "%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &b[i]);
    }
    fclose(f);

    // solving the problem
    buildM(M, m, n, a, b);
    int ansLength = M[m][n];
    int * ans = NULL;
    if (ansLength) {
        ans = new int [ansLength];
    }
    buildAns(M, m, n, a, b, ans);

    // printing the results
    f = fopen("cmlsc.out", "w");
    fprintf(f, "%d\n", ansLength);
    for (int i = ansLength - 1; i >= 0; i--) {
        fprintf(f, "%d ", ans[i]);
    }
    fclose(f);

    // freeing up the resources
    delete [] a;
    delete [] b;
    for (int i = 0; i <= m; i++) {
        delete [] M[i];
    }
    delete [] M;
    if (ans != NULL) {
        delete [] ans;
    }
    return 0;
}