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
    int cur = ans;
    int i = N-1;
    int j = M-1;
    while(i >= 0 && cur) {
        if (i == 0) { R[--cur] = A[i];}
        else if (dp[i][j] == cur && dp[i-1][j] < cur)
        {
            while(dp[i][j] == cur) j--;
            R[--cur] = A[i];
        }
        i--;
    }
    for (int i = 0; i < ans; i++)
        printf("%d%c", R[i], i < ans-1 ? ' ' : '\n');

    return 0;
}

