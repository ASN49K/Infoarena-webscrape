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
    for (int i = 1; i <= M; i++)
        fin >> A[i];
    for (int i = 1; i <= N; i++)
        fin >> B[i];

    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    fout << dp[M][N] << '\n';

    vector<int> lcs;
    int i = M, j = N;
    while (i > 0 && j > 0) {
        if (A[i] == B[j]) {
            lcs.push_back(A[i]);
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());
    for (int x : lcs)
        fout << x << ' ';
    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}