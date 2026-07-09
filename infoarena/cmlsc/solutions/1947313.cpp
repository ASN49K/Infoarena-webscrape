#include <stdio.h>

#define NMAX 1025

int N, M, vN[NMAX], vM[NMAX], dp[NMAX][NMAX], trace[NMAX][NMAX];

int max(int x, int y) {
    return x < y ? y : x;
}

void traceback(int it, int jt) {
    if (it == 0 || jt == 0)
        return;
    
    if (vN[it] == vM[jt]) {
        traceback(it - 1, jt - 1);
        printf("%d ", vN[it]);
        return;
    }

    if (dp[it][jt - 1] < dp[it - 1][jt])
        traceback(it - 1, jt);
    else
        traceback(it, jt - 1);
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &N, &M);
    for(int it = 1; it <= N; ++it) {
        scanf("%d", &vN[it]);
    }

    for (int it = 1; it <= M; ++it) {
        scanf("%d", &vM[it]);
    }

    for (int it = 1; it <= N; ++it) {
        for (int jt = 1; jt <= M; ++jt) {
            if (vN[it] == vM[jt]) {
                dp[it][jt] = 1 + dp[it - 1][jt - 1];
            } else {
                dp[it][jt] = max(dp[it - 1][jt], dp[it][jt - 1]);
            }
        }
    }

    printf("%d\n", dp[N][M]);
    traceback(N, M);

    fclose(stdin);
    fclose(stdout);

    return 0;
}