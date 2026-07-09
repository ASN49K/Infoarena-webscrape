#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX_SIZE = 1024 + 1;

int dp[MAX_SIZE][MAX_SIZE];
int A[MAX_SIZE], B[MAX_SIZE];
int M, N;

int main() {
    // Citire date de intrare
    fin >> M >> N;
    for (int i = 1; i <= M; i++) fin >> A[i];
    for (int i = 1; i <= N; i++) fin >> B[i];

    // Calcularea matricei dp
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Lungimea maximă a subșirului comun
    fout << dp[M][N] << "\n";

    // Reconstrucția subșirului comun
    vector<int> lcs;
    int i = M, j = N;
    while (i > 0 && j > 0) {
        if (A[i] == B[j]) {
            lcs.push_back(A[i]);
            i--; j--;
        } else if (dp[i-1][j] >= dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    // Inversarea și afișarea rezultatului
    reverse(lcs.begin(), lcs.end());
    for (int x : lcs) fout << x << " ";

    return 0;
}
