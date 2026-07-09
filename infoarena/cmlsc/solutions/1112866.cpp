#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int mx = 1024;

int N, M;
int len = 0;
int bv = -1;

int dp[mx][mx];
int A[mx];
int B[mx];
int R[mx];

inline int max(int a, int b) { return a > b ? a : b; }
inline int max(int a, int b, int c) { return a > b ? max(a, c) : max(b, c); }

int getAns(int n, int m) {
    if (n < 0 || m < 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];

    return dp[n][m] = max(getAns(n-1, m-1) + (A[n] == B[m]),
                  getAns(n-1, m),
                  getAns(n, m-1));
}

int main()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    scanf ("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < M; i++) scanf("%d", &B[i]);
    
    memset(dp, -1, sizeof(dp));
    dp[0][0] = A[0] == B[0];
    int ans = getAns(N-1, M-1);
    printf("%d\n", ans);
    /*
    for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
        printf("%d_", dp[i][j]);
    printf("\n");
    }
    */
    int cur = 0;
    for (int i = 0; i < N && cur < ans; i++) {
        if (cur < dp[i][M-1]) {
            cur++;
            printf("%d%c", A[i], cur < ans ? ' ' : '\n');
        }
    }
    return 0;
}
