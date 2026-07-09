//001
#include <cstdio>
#include <algorithm>
#include <list>
#define li list<int>::iterator

using namespace std;

list<int> numere;

void backtrack(int** dp, int* v1, int* v2, int i, int j) {
    if(i == 0 || j == 0)
        return;
    if (v1[i - 1] == v2[j - 1]) {
        numere.push_front(v1[i - 1]);
        backtrack(dp, v1, v2, i - 1, j - 1);
        return;
    }
    if (dp[i - 1][j] > dp[i][j - 1]) {
        backtrack(dp, v1, v2, i - 1, j);
        return;
    } else {
        backtrack(dp, v1, v2, i, j - 1);
        return;
    }
}

int main() {
    FILE* fi = fopen("cmlsc.in", "rt");
    FILE* fo = fopen("cmlsc.out", "wt");

    int n,m;
    fscanf(fi, "%d%d", &n, &m);
    int* v1 = (int*)malloc(n * sizeof(int));
    int* v2 = (int*)malloc(m * sizeof(int));
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++)
        dp[i] = (int*)malloc((m + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i < n; i++)
        fscanf(fi, "%d", &v1[i]);
    for (int j = 0; j < m; j++)
        fscanf(fi, "%d", &v2[j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (v1[i - 1] == v2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    fprintf(fo, "%d\n", dp[n][m]);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }

    backtrack(dp, v1, v2, n, m);

    for (li it = numere.begin(); it != numere.end(); it++)
        fprintf(fo, "%d ", *it);

    return 0;
}
