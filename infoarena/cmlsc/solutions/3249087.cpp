#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <algorithm>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int main() {
    int N, M;
    fin >> N >> M;

    std::vector<int> A(N + 1), B(M + 1);
    std::vector<std::vector<int> > dp(1024, std::vector<int> (1024));

    for (int i = 1; i <= N; ++i) fin >> A[i];
    for (int i = 1; i <= M; ++i) fin >> B[i];

    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            if (A[i] == B[j]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    fout << dp[N][M] << '\n';

    // Reconstruct:
    int i = N, j = M;
    std::vector<int> ans;
    while (i > 0 && j > 0) {
        if (A[i] == B[j]) {
            ans.push_back(A[i]);
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    for (auto elem : ans) {
        fout << elem << " ";
    }

    return 0;
}

