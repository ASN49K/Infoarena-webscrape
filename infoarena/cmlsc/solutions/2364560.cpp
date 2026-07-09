#include <cstdio>

#define MAX_LENGTH 1025

int N, M, n[MAX_LENGTH], m[MAX_LENGTH], dp[MAX_LENGTH][MAX_LENGTH];

int maximum(int x, int y) {
    return x < y ? y : x;
}

void printLongestCommonSubsequence(int firstIndex, int secondIndex) {
    if (firstIndex < 1 || secondIndex < 1) return;
    if (n[firstIndex] == m[secondIndex]) {
        printLongestCommonSubsequence(firstIndex - 1, secondIndex - 1);
        printf("%d ", n[firstIndex]);
        return;
    }
    if (dp[firstIndex - 1][secondIndex] < dp[firstIndex][secondIndex - 1]) {
        printLongestCommonSubsequence(firstIndex, secondIndex - 1);
    } else {
        printLongestCommonSubsequence(firstIndex - 1, secondIndex);
    }
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &N, &M);
    for (int it = 1; it <= N; ++it) scanf("%d", &n[it]);
    for (int it = 1; it <= M; ++it) scanf("%d", &m[it]);

    for (int it = 1; it <= N; ++it) {
        for (int jt = 1; jt <= M; ++jt) {
            if (n[it] == m[jt]) dp[it][jt] = 1 + dp[it - 1][jt - 1];
            else dp[it][jt] = maximum(dp[it][jt - 1], dp[it -1][jt]);
        }
    }

    printf("%d\n", dp[N][M]);
    printLongestCommonSubsequence(N, M);

    return 0;
}