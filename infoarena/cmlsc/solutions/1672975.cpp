#include <bits/stdc++.h>

FILE* fin = fopen("cmlsc.in", "r");
FILE* fout = fopen("cmlsc.out", "w");

int n, m, a[1025], b[1025], best[1025][1025], sol[1025];

int main() {
    fscanf(fin, "%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        fscanf(fin, "%d", &a[i]);

    for (int i = 1; i <= m; ++i)
        fscanf(fin, "%d", &b[i]);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
                if (a[i] == b[j])
                    best[i][j] = best[i - 1][j - 1] + 1, sol[best[i][j]] = a[i];
                else
                    best[i][j] = std::max(best[i - 1][j], best[i][j - 1]);
            }

    fprintf(fout, "%d\n", best[n][m]);

    for (int i = 1; i <= best[n][m]; ++i)
        fprintf(fout, "%d ", sol[i]);

    fclose(fin), fclose(fout);
    return 0;
}
