#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> seq1, seq2;
vector<vector<int>> DP;

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    cin >> N >> M;
    seq1.assign(N, 0);
    for (int idx = 0; idx < N; idx++) {
        cin >> seq1[idx];
    }
    seq2.assign(M, 0);
    for (int idx = 0; idx < M; idx++) {
        cin >> seq2[idx];
    }
    DP.assign(N + 1, vector<int>(M + 1, 0));
    for (int idx1 = 1; idx1 <= N; idx1++) {
        for (int idx2 = 1; idx2 <= M; idx2++) {
            if (idx1 > 0) {
                DP[idx1][idx2] = max(DP[idx1][idx2], DP[idx1 - 1][idx2]);
            }
            if (idx2 > 0) {
                DP[idx1][idx2] = max(DP[idx1 - 1][idx2], DP[idx1][idx2 - 1]);
            }
            if (seq1[idx1 - 1] == seq2[idx2 - 1]) {
                DP[idx1][idx2] = 1 + DP[idx1 - 1][idx2 - 1];
            }
        }
    }
    cout << DP[N][M] << "\n";
    vector<int> sol;
    sol.reserve(DP[N][M]);
    int idx1 = N, idx2 = M;
    while (idx1 && idx2) {
        if (seq1[idx1 - 1] == seq2[idx2 - 1]) {
            sol.push_back(seq1[idx1 - 1]);
            idx1--;
            idx2--;
        } else if (DP[idx1][idx2] == DP[idx1 - 1][idx2]) {
            idx1--;
        } else {
            idx2--;
        }
    }
    reverse(sol.begin(), sol.end());
    for (int idx = 0; idx < sol.size(); idx++) {
        if (idx > 0) {
            cout << " ";
        }
        cout << sol[idx];
    }
    cout << "\n";
    return 0;
}