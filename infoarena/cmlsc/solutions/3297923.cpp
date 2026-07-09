#include <bits/stdc++.h>
#define N_MAX 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M, N;
int A[N_MAX], B[N_MAX];

int dp[N_MAX][N_MAX], seq[N_MAX];

void LongestCommonSubsequence() {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

void SequenceReconstruction(int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (A[i] == B[j]) {
        seq[dp[i][j]] = A[i];
        SequenceReconstruction(i - 1, j - 1);
    }
    else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
            SequenceReconstruction(i - 1, j);
        }
        else {
            SequenceReconstruction(i, j - 1);
        }
    }
}

int main() {
    fin >> M >> N;
    for (int i = 1; i <= M; i++) {
        fin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        fin >> B[i];
    }

    LongestCommonSubsequence();
    SequenceReconstruction(M, N);
    
    fout << dp[M][N] << "\n";
    for (int i = 1; i <= dp[M][N]; i++) {
        fout << seq[i] << " ";
    }
    return 0;
}