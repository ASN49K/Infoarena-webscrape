#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int M, N;
    fin >> M >> N;

    vector<int> A(M + 1), B(N + 1);
    for (int i = 1; i <= M; ++i) fin >> A[i];
    for (int j = 1; j <= N; ++j) fin >> B[j];

    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[M][N];
    fout << length << "\n";

    if (length > 0) {
        vector<int> lcs(length);
        int i = M, j = N;
        int k = length - 1;
        while (i > 0 && j > 0) {
            if (A[i] == B[j]) {
                lcs[k--] = A[i];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        for (int x = 0; x < length; ++x) {
            if (x > 0) fout << " ";
            fout << lcs[x];
        }
        fout << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}