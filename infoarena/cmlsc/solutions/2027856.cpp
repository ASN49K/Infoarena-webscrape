#include <cstdio>

FILE *fin = fopen("cmlsc.in", "r");
FILE *fout = fopen("cmlsc.out", "w");

#define maxn 1024

int d[maxn + 1][maxn + 1];
int a[maxn + 1];
int b[maxn + 1];
int rez[maxn + 1];
inline int dp(int m, int n) {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else {
                d[i][j] = d[i - 1][j];
                if (d[i][j] < d[i][j - 1])
                    d[i][j] = d[i][j - 1];

            }
    }
    return d[m][n];
}

void bkt (int i, int j) {
    if (i == 0 || j == 0);

    else if (a[i] == b[j]) {
        rez[d[i][j]] = a[i];
        return bkt (i - 1, j - 1);
    }
    else {
        if (d[i - 1][j] >= d[i][j - 1])
            return bkt (i - 1, j);
        else
            return bkt (i, j - 1);
    }
}

int main() {
    int m, n;
    fscanf (fin, "%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        fscanf(fin, "%d", &a[i]);
    for (int i = 1; i <= m; i++)
        fscanf(fin, "%d", &b[i]);
    int max = dp(m, n);
    fprintf(fout, "%d\n", max);
    bkt (m, n);
    for (int i = 1; i <= max; i++)
        fprintf(fout, "%d ", rez[i]);
    return 0;
}
