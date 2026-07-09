#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1025][1025];
int main() {
    int M, N;
    fin >> M >> N;

    int A[1025], B[1025];
    for (int i = 1; i <= M; i++)
        fin >> A[i];
    for (int j = 1; j <= N; j++)
        fin >> B[j];
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    fout << dp[M][N] << "\n";
    int i = M, j = N;
    int sol[1025], k = 0;
    while (i > 0 && j > 0) {
        if (A[i] == B[j]) {
            sol[k++] = A[i];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    for (int x = k - 1; x >= 0; x--)
        fout << sol[x] << " ";

    return 0;
}
