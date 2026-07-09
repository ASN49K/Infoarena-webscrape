#include <cstdio>
#define MAX_LENGTH 1025

using namespace std;

    FILE *f = fopen("cmlsc.in", "r");
    FILE *g = fopen("cmlsc.out", "w");
    int x[MAX_LENGTH], y[MAX_LENGTH];
    int c[MAX_LENGTH][MAX_LENGTH];

void print(int i, int j) {
    while (c[i][j-1] == c[i][j] && c[i-1][j] == c[i][j]) {
        if (c[i][j-1] == c[i][j])
            j--;
        else i--;
    }
    if (c[i][j] > 0) {
        print(i-1, j-1);
        fprintf(g, "%d ", y[j-1]);
    }
}

int main()
{
    int m, n, i, j;
    fscanf(f, "%d%d", &m, &n);
    for (i = 0; i < m; ++i)
        fscanf(f, "%d", &x[i]);
    for (i = 0; i < n; ++i)
        fscanf(f, "%d", &y[i]);

    for (i = 1; i <= m; ++i)
        for (j = 1; j <= n; ++j)
            if (x[i-1] == y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else if (c[i-1][j] > c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];
    fprintf(g, "%d\n", c[m][n]);
    print(m, n);
    fclose(f);
    fclose(g);
    return 0;
}
