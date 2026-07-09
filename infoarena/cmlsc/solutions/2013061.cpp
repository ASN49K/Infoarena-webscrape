#include <bits/stdc++.h>

using namespace std;

vector<int> A, B, res;
int DP[1200][1200], N, M;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &N, &M);
    A.resize(N + 1);
    B.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= M; ++i) {
        scanf("%d", &B[i]);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i] == B[j]) {
                DP[i][j] = max(DP[i][j], DP[i-1][j-1] + 1);
            }
            else {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }

    printf("%d\n", DP[N][M]);
    int i = N, j = M;
    while (DP[i][j]) {
        if (DP[i][j] == DP[i-1][j-1] + 1) {
            res.push_back(DP[i][j]);
        }
        else {
            if( DP[i][j-1] >= DP[i-1][j] ) {
                --j;
            }
            else {
                --i;
            }
        }
    }
    reverse(res.begin(), res.end());
    for (auto it : res)
        printf("%d ", it);
    printf("\n");

    return 0;
}
